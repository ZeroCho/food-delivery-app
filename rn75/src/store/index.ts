import {configureStore} from '@reduxjs/toolkit';
import {useDispatch} from 'react-redux';
import rootReducer from './reducer';

const store = configureStore({
  reducer: rootReducer,
  middleware: getDefaultMiddleware => {
    return getDefaultMiddleware();
  },
});
export default store;

export type AppDispatch = typeof store.dispatch;
export const useAppDispatch = () => useDispatch<AppDispatch>();
