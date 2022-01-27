import React, {useCallback, useRef, useState} from 'react';
import {
  Alert,
  Pressable,
  StyleSheet,
  Text,
  TextInput,
  View,
  ActivityIndicator,
} from 'react-native';
import {NativeStackScreenProps} from '@react-navigation/native-stack';
import EncryptedStorage from 'react-native-encrypted-storage';
import DismissKeyboardView from '../components/DismissKeyboardView';
import axios, {AxiosError} from 'axios';
import Config from 'react-native-config';
import {RootStackParamList} from '../../AppInner';
import {useAppDispatch} from '../store';
import userSlice from '../slices/user';

type SignInScreenProps = NativeStackScreenProps<RootStackParamList, 'SignIn'>;

function SignIn({navigation}: SignInScreenProps) {
  const dispatch = useAppDispatch();
  const [loading, setLoading] = useState(false);
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const emailRef = useRef<TextInput | null>(null);
  const passwordRef = useRef<TextInput | null>(null);

  const onChangeEmail = useCallback(text => {
    setEmail(text.trim());
  }, []);
  const onChangePassword = useCallback(text => {
    setPassword(text.trim());
  }, []);
  const onSubmit = useCallback(async () => {
    if (loading) {
      return;
    }
    if (!email || !email.trim()) {
      return Alert.alert('알림', '이메일을 입력해주세요.');
    }
    if (!password || !password.trim()) {
      return Alert.alert('알림', '비밀번호를 입력해주세요.');
    }
    try {
      setLoading(true);
      const response = await axios.post(`${Config.API_URL}/login`, {
        email,
        password,
      });
      console.log(response.data);
      Alert.alert('알림', '로그인 되었습니다.');
      dispatch(
        userSlice.actions.setUser({
          name: response.data.data.name,
          email: response.data.data.email,
          accessToken: response.data.data.accessToken,
        }),
      );
      await EncryptedStorage.setItem(
        'refreshToken',
        response.data.data.refreshToken,
      );
    } catch (error) {
      const errorResponse = (error as AxiosError).response;
      if (errorResponse) {
        Alert.alert('알림', errorResponse.data.message);
      }
    } finally {
      setLoading(false);
    }
  }, [loading, dispatch, email, password]);

  const toSignUp = useCallback(() => {
    navigation.navigate('SignUp');
  }, [navigation]);

  const canGoNext = email && password;
  return (
    <DismissKeyboardView>
      <View style={styles.inputWrapper}>
        <Text style={styles.label}>이메일</Text>
        <TextInput
          style={styles.textInput}
          onChangeText={onChangeEmail}
          placeholder="이메일을 입력해주세요"
          placeholderTextColor="#666"
          importantForAutofill="yes"
          autoComplete="email"
          textContentType="emailAddress"
          value={email}
          returnKeyType="next"
          clearButtonMode="while-editing"
          ref={emailRef}
          onSubmitEditing={() => passwordRef.current?.focus()}
          blurOnSubmit={false}
        />
      </View>
      <View style={styles.inputWrapper}>
        <Text style={styles.label}>비밀번호</Text>
        <TextInput
          style={styles.textInput}
          placeholder="비밀번호를 입력해주세요(영문,숫자,특수문자)"
          placeholderTextColor="#666"
          importantForAutofill="yes"
          onChangeText={onChangePassword}
          value={password}
          autoComplete="password"
          textContentType="password"
          secureTextEntry
          returnKeyType="send"
          clearButtonMode="while-editing"
          ref={passwordRef}
          onSubmitEditing={onSubmit}
        />
      </View>
      <View style={styles.buttonZone}>
        <Pressable
          style={
            canGoNext
              ? StyleSheet.compose(styles.loginButton, styles.loginButtonActive)
              : styles.loginButton
          }
          disabled={!canGoNext || loading}
          onPress={onSubmit}>
          {loading ? (
            <ActivityIndicator color="white" />
          ) : (
            <Text style={styles.loginButtonText}>로그인</Text>
          )}
        </Pressable>
        <Pressable onPress={toSignUp}>
          <Text>회원가입하기</Text>
        </Pressable>
      </View>
    </DismissKeyboardView>
  );
}

const styles = StyleSheet.create({
  textInput: {
    padding: 5,
    borderBottomWidth: StyleSheet.hairlineWidth,
  },
  inputWrapper: {
    padding: 20,
  },
  label: {
    fontWeight: 'bold',
    fontSize: 16,
    marginBottom: 20,
  },
  buttonZone: {
    alignItems: 'center',
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

export default SignIn;
