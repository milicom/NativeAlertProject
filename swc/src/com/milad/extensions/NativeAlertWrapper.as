package com.milad.extensions {
    import flash.events.EventDispatcher;
    import flash.events.IEventDispatcher;
    import flash.events.StatusEvent;
    import flash.external.ExtensionContext;

    public class NativeAlertWrapper extends EventDispatcher {
        // Constructor: Initialize the ExtensionContext and listen for status events
        public function NativeAlertWrapper(_target: IEventDispatcher = null) {
            super(_target);

            // Create a new extension context and add event listener for status events
            m_extContext = ExtensionContext.createExtensionContext(EXTENSION_ID, null);
            m_extContext.addEventListener(StatusEvent.STATUS, onStatusEvent);
        }

        // Handle any status events sent from the native code (e.g. logging, error handling)
        private function onStatusEvent(event: StatusEvent): void {
            trace("Status Event: " + event.code + " - " + event.level);
        }

        // Function to call the native alert function with customizable parameters
        public function showAlert(message: String, buttonLabel: String, title: String): void {
            // Call the C++ function defined in the native code with the parameters
            m_extContext.call("show_native_alert", message, buttonLabel, title);
        }

        // Clean up the ExtensionContext when it's no longer needed
        public function dispose(): void {
            if (m_extContext) {
                m_extContext.removeEventListener(StatusEvent.STATUS, onStatusEvent);
                m_extContext.dispose();
                m_extContext = null;
            }
        }

        // Private members
        private var m_extContext: ExtensionContext;

        // The extension ID should match your extension context in the native code
        private static const EXTENSION_ID: String = "com.milad.extensions.NativeAlert";
    }
}
