# NativeAlertWrapper - Adobe Native Extension for Windows

## Overview
NativeAlertWrapper is an Adobe Native Extension (ANE) designed for Adobe AIR applications on Windows. It provides a simple way to show native alert dialogs with customizable messages, button labels, and titles.

## Features
- Display a native Windows alert with customizable message and button label.
- Supports setting a custom title for the alert dialog.

## Requirements
- Adobe AIR SDK 51.1 or later
- Windows operating system

## Installation

1. **Download the NativeAlertWrapper.ane**: Ensure you have the latest version of the `.ane` file.

2. **Add the ANE to your Project**:
   - Place the `NativeAlertWrapper.ane` file in your project directory.
   - When compiling your AIR application, add the following parameter to the ADT command:
     ```
     -extdir path/to/your/ANE/directory
     ```
   - Alternatively, you can specify the ANE directly in your build configuration (e.g., `-use-network=false -use-code-signing=false`).

3. **Include the NativeAlertWrapper in Your Code**:
   - Import the NativeAlertWrapper class in your ActionScript code:
     ```actionscript
     import com.milad.extensions.NativeAlertWrapper;
     ```

## Usage

### Initializing the Wrapper
To use the NativeAlertWrapper, you need to create an instance of it in your code:

```actionscript
var alertWrapper:NativeAlertWrapper = new NativeAlertWrapper();
```

### Showing an Alert
You can display a native alert by calling the `showAlert` method:

```actionscript
alertWrapper.showAlert("This is a custom message!", "OK", "Custom Title");
```

### Cleanup
When you are done with the alert wrapper, dispose of it properly to free up resources:

```actionscript
alertWrapper.dispose();
```

## Example
Here’s a simple example of how to use the NativeAlertWrapper in an Adobe AIR application:

```actionscript
import com.milad.extensions.NativeAlertWrapper;

var alertWrapper:NativeAlertWrapper = new NativeAlertWrapper();
alertWrapper.showAlert("Hello, World!", "OK", "Greetings");
```

## License
This project is licensed under the MIT License.

## Contributing
Contributions are welcome! If you have suggestions or improvements, feel free to open an issue or submit a pull request.

## Contact
For any inquiries or support, please contact [Milad](mailto:miladtaban@gmail.com.com).
