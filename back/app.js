const express = require("express");
const morgan = require("morgan");
const jwt = require("jsonwebtoken");
const app = express();
const SocketIO = require("socket.io");

app.use(morgan("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

const jwtSecret = "JWT_SECRET";
const users = {};

const verifyToken = (req, res, next) => {
  console.log(req.headers);
  if (!req.headers.authorization) {
    return res.status(401).json({ message: "토큰이 없습니다." });
  }
  try {
    const data = jwt.verify(req.headers.authorization);
    res.locals.email = data.email;
  } catch (error) {}
  next();
};

app.post("/refreshToken", verifyToken, (req, res, next) => {});

app.post("/user", (req, res, next) => {
  if (users[req.body.email]) {
    return res.status(401).json({ message: "이미 가입한 회원입니다." });
  }
  users[req.body.email] = {
    email: req.body.email,
    password: req.body.password,
    name: req.body.name,
  };

  return res.json({
    data: {
      email: req.body.email,
      name: req.body.name,
    },
  });
});

app.post("/login", (req, res, next) => {
  if (!users[req.body.email]) {
    return res.status(401).json({ message: "가입하지 않은 회원입니다." });
  }
  if (req.body.password !== users[req.body.email].password) {
    return res.status(401).json({ message: "잘못된 비밀번호입니다." });
  }
  const refreshToken = jwt.sign(
    { sub: "refresh", email: req.body.email },
    jwtSecret,
    { expiresIn: "24h" }
  );
  const accessToken = jwt.sign(
    { sub: "access", email: req.body.email },
    jwtSecret,
    { expiresIn: "5m" }
  );
  users[req.body.email].refreshToken = refreshToken;
  return res.json({
    data: {
      name: users[req.body.email].name,
      email: req.body.email,
      refreshToken,
      accessToken,
    },
  });
});
app.post("/logout", verifyToken, (req, res, next) => {
  delete users[res.locals.email];
  res.json({ message: "ok" });
});

app.post("/accept", verifyToken, (req, res, next) => {});
app.post("/complete", verifyToken, (req, res, next) => {});
app.get("/point", verifyToken, (req, res, next) => {});

app.use((err, req, res, next) => {
  console.error(err);
  res.status(500).json(err);
});

const server = app.listen(3105, () => {
  console.log("연결되었습니다.");
});

const io = SocketIO(server, {
  path: "/socket.io",
});
app.set("io", io);

io.on("connection", (socket) => {
  let id;
  console.log(socket.id, "연결되었습니다.");
  socket.on("login", () => {
    console.log(socket.id, "로그인했습니다.");
    id = setInterval(() => {
      io.emit("hello", "emit");
    }, 1000);
  });
  socket.on("disconnect", () => {
    console.log(socket.id, "연결 끊었습니다..");
    if (id) {
      clearInterval(id);
    }
  });
});
