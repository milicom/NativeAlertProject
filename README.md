# Native Alert Wrapper for Adobe AIR

## Overview

The **Native Alert Wrapper** is an Adobe AIR extension designed to display native alert dialogs on Windows. This wrapper allows you to create customizable alert messages with user-defined button labels and titles, enhancing user experience in your AIR applications.

## Features

- Display native alert dialogs using the Windows MessageBox.
- Customizable parameters for alert messages, button labels, and titles.
- Simple integration into existing Adobe AIR applications.

## Requirements

- Adobe AIR SDK version 51.1 or later.
- Windows operating system.

## Installation

1. **Download the Project:**
   Clone or download this repository to your local machine.

   ```bash
   git clone https://github.com/yourusername/NativeAlertProject.git
   ```

2. **Add the Extension to Your Project:**
   - Copy the compiled `.swc` file to your Adobe AIR project directory.
   - Add the `.swc` file to your project settings in your IDE.

3. **Include the Extension in Your Application:**
   Add the following import statement to your ActionScript files:

   ```actionscript
   import com.milad.extensions.NativeAlertWrapper;
   ```

## Usage

### Initializing the Native Alert Wrapper

To use the `NativeAlertWrapper`, you first need to create an instance of it:

```actionscript
var alertWrapper:NativeAlertWrapper = new NativeAlertWrapper();
```

### Showing an Alert

To show an alert, call the `showAlert` method with your desired message, button label, and title:

```actionscript
alertWrapper.showAlert("This is a sample alert message.", "OK", "Alert Title");
```

### Cleaning Up

When you're done using the wrapper, ensure to call the `dispose` method to clean up resources:

```actionscript
alertWrapper.dispose();
```

## Example

Here’s a complete example demonstrating how to use the Native Alert Wrapper:

```actionscript
import com.milad.extensions.NativeAlertWrapper;

var alertWrapper:NativeAlertWrapper = new NativeAlertWrapper();
alertWrapper.showAlert("This is an alert message.", "OK", "Alert Title");
// Dispose the alert wrapper when done
alertWrapper.dispose();
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## Contact

For any inquiries or issues, please contact:

- [Your Name](mailto:your-email@example.com)
- [GitHub Profile](https://github.com/yourusername)
