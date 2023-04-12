import React, {useCallback, useEffect} from 'react';
import {
  Alert,
  Dimensions,
  FlatList,
  Pressable,
  StyleSheet,
  Text,
  View,
} from 'react-native';
import axios, {AxiosError} from 'axios';
import Config from 'react-native-config';
import orderSlice, {Order} from '../slices/order';
import {useAppDispatch} from '../store';
import userSlice from '../slices/user';
import {useSelector} from 'react-redux';
import {RootState} from '../store/reducer';
import EncryptedStorage from 'react-native-encrypted-storage';
import FastImage from 'react-native-fast-image';

function Settings() {
  const accessToken = useSelector((state: RootState) => state.user.accessToken);
  const completes = useSelector((state: RootState) => state.order.completes);
  const money = useSelector((state: RootState) => state.user.money);
  const name = useSelector((state: RootState) => state.user.name);
  const dispatch = useAppDispatch();

  useEffect(() => {
    async function getMoney() {
      const response = await axios.get<{data: number}>(
        `${Config.API_URL}/showmethemoney`,
        {
          headers: {authorization: `Bearer ${accessToken}`},
        },
      );
      dispatch(userSlice.actions.setMoney(response.data.data));
    }
    getMoney();
  }, [accessToken, dispatch]);

  useEffect(() => {
    async function getCompletes() {
      const response = await axios.get<{data: number}>(
        `${Config.API_URL}/completes`,
        {
          headers: {authorization: `Bearer ${accessToken}`},
        },
      );
      console.log('completes', response.data);
      dispatch(orderSlice.actions.setCompletes(response.data.data));
    }
    getCompletes();
  }, [dispatch, accessToken]);

  const onLogout = useCallback(async () => {
    try {
      await axios.post(
        `${Config.API_URL}/logout`,
        {},
        {
          headers: {
            Authorization: `Bearer ${accessToken}`,
          },
        },
      );
      Alert.alert('알림', '로그아웃 되었습니다.');
      dispatch(
        userSlice.actions.setUser({
          name: '',
          email: '',
          accessToken: '',
        }),
      );
      await EncryptedStorage.removeItem('refreshToken');
    } catch (error) {
      const errorResponse = (error as AxiosError).response;
      console.error(errorResponse);
    }
  }, [accessToken, dispatch]);

  const renderItem = useCallback(({item}: {item: Order}) => {
    return (
      <FastImage
        source={{uri: `${Config.API_URL}/${item.image}`}}
        resizeMode="contain"
        style={{
          height: Dimensions.get('window').width / 3,
          width: Dimensions.get('window').width / 3,
        }}
      />
    );
  }, []);

  return (
    <View>
      <View style={styles.money}>
        <Text style={styles.moneyText}>
          {name}님의 수익금{' '}
          <Text style={{fontWeight: 'bold'}}>
            {money.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ',')}
          </Text>
          원
        </Text>
      </View>
      <View>
        <FlatList
          data={completes}
          numColumns={3}
          keyExtractor={o => o.orderId}
          renderItem={renderItem}
        />
      </View>
      <View style={styles.buttonZone}>
        <Pressable
          style={StyleSheet.compose(
            styles.loginButton,
            styles.loginButtonActive,
          )}
          onPress={onLogout}>
          <Text style={styles.loginButtonText}>로그아웃</Text>
        </Pressable>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  money: {
    padding: 20,
  },
  moneyText: {
    fontSize: 16,
  },
  buttonZone: {
    alignItems: 'center',
    paddingTop: 20,
  },
  loginButton: {
    backgroundColor: 'gray',
    paddingHorizontal: 20,
    paddingVertical: 10,
    borderRadius: 5,
    marginBottom: 10,
  },
  loginButtonActive: {
    backgroundColor: 'blue',
  },
  loginButtonText: {
    color: 'white',
    fontSize: 16,
  },
});

export default Settings;
