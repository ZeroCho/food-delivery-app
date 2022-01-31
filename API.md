## REST API
- 주소는 http://localhost:3105
### POST /user
- 회원가입
- data: { email, name, password }
- error: { status: 400, data: { message: '이미 가입한 회원입니다.' } }
### POST /login
- 로그인
- data: { email, password }
- responseData: { data: { name, email, accessToken } }
- error: { status: 400, data: { message: '가입되지 않은 회원입니다.' } }
- error: { status: 400, data: { message: '잘못된 비밀번호입니다.' } }
### POST /logout
- header: { authorization: 'Bearer 액세스토큰' }
- error: { status: 419, data: { code: 'expired', message: '만료된 액세스 토큰입니다.' } }
### POST /refreshToken
- header: { authorization: 'Bearer 리프레시토큰' }
- responseData: { data: { name, email, accessToken } }
- error: { status: 419, data: { code: 'expired', message: '만료된 리프레시 토큰입니다.' } }
### POST /accept
- header: { authorization: 'Bearer 액세스토큰' }
- data: { orderId: string }
- error: { status: 419, data: { code: 'expired', message: '만료된 액세스 토큰입니다.' } }
- error: { status: 400, data: { message: '다른 사람이 이미 수락한 주문입니다.' } }
### POST /complete
- header: { authorization: 'Bearer 액세스토큰', content-type: 'multipart/form-data' }
- data: { orderId: string, image: 폼데이터 }
- error: { status: 419, data: { code: 'expired', message: '만료된 액세스 토큰입니다.' } }
### POST /phonetoken
- 폰토큰을 서버로 보냄
- data: { token: string }
### GET /showmethemoney
- header: { authorization: 'Bearer 액세스토큰' }
- responseData: { data: number }
- error: { status: 419, data: { code: 'expired', message: '만료된 액세스 토큰입니다.' } }
### GET /completes
- 완료 내역 가져오기
- header: { authorization: 'Bearer 액세스토큰' }
- responseData: { data: Order[] }

## Websocket
### socket.on('hello', callback)
서버에서 emit 문자열 데이터를 주기적으로 보내줌

### socket.on('order', callback)
서버에서 주문접수 시 주문 정보를 보내줌.
- 단, socket.emit('acceptOrder', 아무값이나)를 호출해서 서버로 주문 접수받을 것임을 알려야 함.
- data
```
export interface Order {
  orderId: string;
  start: {
    latitude: number;
    longitude: number;
  };
  end: {
    latitude: number;
    longitude: number;
  };
  price: number;
}
```
### socket.on('acceptOrder')
지금부터 주문을 받기 시작합니다.
### socket.on('ignoreOrder')
지금부터 주문을 무시합니다.
