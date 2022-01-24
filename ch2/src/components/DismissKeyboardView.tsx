import React from 'react';
import {
  TouchableWithoutFeedback,
  Keyboard,
  StyleProp,
  ViewStyle,
} from 'react-native';
import {KeyboardAwareScrollView} from 'react-native-keyboard-aware-scrollview';

const DismissKeyboardHOC = (
  Comp: typeof KeyboardAwareScrollView,
): React.FC<{style?: StyleProp<ViewStyle>}> => {
  return ({children, ...props}) => (
    <TouchableWithoutFeedback onPress={Keyboard.dismiss} accessible={false}>
      <Comp {...props} style={props.style}>
        {children}
      </Comp>
    </TouchableWithoutFeedback>
  );
};
const DismissKeyboardView = DismissKeyboardHOC(KeyboardAwareScrollView);

export default DismissKeyboardView;
