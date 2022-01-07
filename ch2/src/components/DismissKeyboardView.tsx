import React from 'react';
import {
  TouchableWithoutFeedback,
  Keyboard,
  StyleProp,
  ViewStyle,
  KeyboardAvoidingView,
  Platform,
} from 'react-native';

const DismissKeyboardHOC = (
  Comp: typeof KeyboardAvoidingView,
): React.FC<{style?: StyleProp<ViewStyle>}> => {
  return ({children, ...props}) => (
    <TouchableWithoutFeedback onPress={Keyboard.dismiss} accessible={false}>
      <Comp
        {...props}
        style={props.style}
        behavior={Platform.OS === 'android' ? undefined : 'padding'}>
        {children}
      </Comp>
    </TouchableWithoutFeedback>
  );
};
const DismissKeyboardView = DismissKeyboardHOC(KeyboardAvoidingView);

export default DismissKeyboardView;
