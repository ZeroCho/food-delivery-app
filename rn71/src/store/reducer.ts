import {combineReducers} from 'redux';

import userSlice from '../slices/user';
import orderSlice from '../slices/order';

const rootReducer = combineReducers({
  user: userSlice.reducer,
  order: orderSlice.reducer,
});

export type RootState = ReturnType<typeof rootReducer>;
export default rootReducer;
