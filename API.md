## REST API
- 주소는 http://localhost:3105
### POST /user
- 회원가입
- data: { email, name, password }
### POST /login
- 로그인
- data: { email, password }
- responseData: { data: { name, email, accessToken } }
### POST /logout
- header: { authorization: 'Bearer 액세스토큰' }
### POST /accept
- header: { authorization: 'Bearer 액세스토큰' }
- data: { orderId: string }
### POST /complete
- header: { authorization: 'Bearer 액세스토큰', content-type: 'multipart/form-data' }
- data: { orderId: string, image: 폼데이터 }

### GET /showmethemoney
- header: { authorization: 'Bearer 액세스토큰' }
- responseData: { data: number }

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
