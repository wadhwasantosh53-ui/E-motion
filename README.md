# E-MOTION
Compact native Java implementation of the supplied design, not a verbatim Kotlin/Compose copy. Uses paired Bluetooth Classic devices, no discovery, no fake telemetry. Build untested.
Import ZIP into SPCK for editing. Push extracted contents (including hidden .github folder) to a GitHub repository root. Actions > Build E-MOTION APK > successful run > Artifacts > download ZIP > extract APK. SPCK cannot compile Android APKs.
Pair HC-05 in Android settings first. Upload Arduino sketch using AFMotor v1 library. TXD to A0, RXD disconnected. Test wheels lifted with teacher supervision; verify motor polarity and suitable motor power supply. Do not connect dynamo directly to lithium battery. STOP releases motors (coasting). Firmware timeout 1 second.
