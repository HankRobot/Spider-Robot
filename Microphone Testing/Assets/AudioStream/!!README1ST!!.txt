Hi, welcome and thanks for your interest in AudioStream !


Please read carefully before anything else!
===========================================

AudioStream uses FMOD Studio functionality to stream audio from network, which redistribution is not allowed for 3rd party SDKs ( such as this one ).
Therefore, when you first import AudioStream into a new project a bunch of compile errors CS0246 will occur, stating 'The type or namespace name `FMOD' could not be found. Are you missing a using directive or an assembly reference?'
This is normal and will be resolved once you manually import the FMOD Studio Unity package.

The FMOD Studio Unity package is available at

== FMOD downloads: http://www.fmod.org/download/

You will need "Unity Integration for Windows/Mac/Linux/iOS/Android/WinPhone V2.0" ( Version 1.08.05 at the time of first release - all later versions _should_ work too, see iOS specific remarks below ).

==== 
NOTE: you have to agree to the FMOD EULA before downloading and you are bound by it by using this asset (their licensing policy is very friendly to indies).

==== 
NOTE: AudioStream uses only low level API of FMOD Studio and only really requires the "Plugins" folder from the FMOD package.
(the Plugins folder contains C# wrapper for FMOD and all necessary platform specific plugins, the rest of the package enables live editing of FMOD project and access to its more advanced capabilities.)
You are free to delete everything else, atm this means:
( FMOD specific files in ) Editor, Editor Default Resources, Gizmos, Resources, StreamingAssets, Plugins/Editor and all files in Plugins/FMOD _EXCEPT_ Plugins/FMOD/Wrapper.

Once the FMOD Studio Unity package is successfully imported and setup, AudioStream is ready to use.

===========================================
Usage instructions:
===========================================

AudioStream provides two main ways to stream audio - the first completely bypasses Unity audio (playing at stream specified sample rate) while the second one
behaves like a standard AudioSource enabling all usual functionality such as 3D spatialisation, effecting and mixing with other Unity audio sources.

First component is
  AudioStreamMinimal,
  component for 'normal' Unity AudioSource is called AudioStream.

Both have reliable network loss detection and recovery and can stream all supported audio formats locally or over the network.
(NOTE: it is very important to select proper audio type especially for OGG streams since the internal codec cannot recognise wrong audio type which leads to problems and instabilities when releasing it later.)

Each component further provides selective Console logging and UnityEvent messages.

As a source a http link to a PLS or M3U/8 playlist distributed commonly by web/net radio stations, a http link to a remote file such as podcast which is then streamed in full,
or a local filesystem path to a file can be specified.

====
NOTE: the first entry from playlist is played. This is usually the correct stream, but if there are more than one streams specified
you'd have to extract desired stream/link from the downloaded playlist manually.

====
NOTE: Any necessary resampling is done by Unity automatically.


Streaming was tested on iOS, Android, Windows and OS X.


===========================================
Supported formats:
===========================================

AudioStream can stream all formats FMOD recognises. For complete list see https://en.wikipedia.org/wiki/FMOD#File_formats
RAW format is supported also by exposing format values in the AudioStream/AudioStreamMinimal Inspector since these must be set explicitly by user.


===========================================
Non system default audio output:
===========================================

As of 1.3 it is possible to specify other than system default audio output for AudioStreamMinimal component directly and for AudioStream ( or any AudioSource ) via
AudioSourceOutputDevice component.

AudioSourceOutputDevice can be used separately from AudioStream for any AudioSource but you have to start and stop the redirection manually (if not using its automatic startup).
For use with AudioStream keep automatic startup disabled as AudioStream detects AudioSourceOutputDevice automatically and starts redirection too when sample rate/stream is acquired.

The output is set by Output Driver ID - 0 means current system default output. For all driver IDs currently recognised by FMOD in your system please run the OutputDeviceDemo demo scene and see
its Start() method where all outputs are evaluated and printed to Console.

If you don't need output redirection it is better to not attach AudioSourceOutputDevice as it currently has some performance implications even when outputting to default device ( driver with id 0 ) - this is true _especially_ for mobiles.

Note: AudioSourceOutputDevice should be the last component in OAFR chain as it silences the Unity audio output buffer. This behaviour can be changed in source - see end of OnAudioFilterRead method of AudioSourceOutputDevice.

Note: Ensure that DSP Bufer Size in Project Settings - Audio is NOT set to 'Best latency' - otherwise the internal buffer has problems catching up and data won't be passed around correctly; I don't know the exact cause so far.

Note: at least version 1.08.11 of FMOD Unity Integration is needed as it contains a bug fix for AudioSourceOutputDevice to work.


===========================================
Audio input:
===========================================

As of version 1.4 it is possible to stream audio from any available system recording input - just attach AudioSourceInput component to an empty game object and from custom script access audio buffer data of AudioSource which it automatically creates.
See how to interact with it in the AudioStreamInputDemo scene.

For iOS/mobiles see specific recording notes below.

===========================================
===========================================

Please consider redirection - AudioSourceOutputDevice component - a desktop class feature - due to variety of different issues I had on my testing Android and iOS devices (with various versions of Unity and relevant development tools) I don't recommend using it on mobiles for now.



===========================================
3D spatialisation
===========================================

As of 1.5 all streams including input can be fully spatialised by Unity by adjusting Spatial Blend on AudioSource.
Possibly the most simple usage is demonstrated in the ThreeDDemo scene together with AudioStream, and AudioStreamInput.


===========================================
iOS Build notes:
===========================================

- Since FMOD Version 1.09 added support for Google VR and the respective plugin is not Bitcode enabled it is necessary to not build Xcode project with Bitcode support - or, if you don't need Google VR plugin, simply delete libgvraudio plugin/library.
- arbitrary loads for app transport security settings should be enabled ( newer versions of Unity handle this automatically via Allow HTTP downloads in Player settings )


===========================================
iOS recording notes:
===========================================

- check 'Prepare iOS For Recording' in iOS Player Settings / Other settings
- ensure that DSP Bufer Size in Project Settings - Audio is set to 'Best latency' - otherwise recording won't work; - tested on Unity 5.3.5f1 - unsure if applicable for all later versions.
- add 'Privacy - Microphone Usage Description' ( raw value NSMicrophoneUsageDescription ) key and its value to Info.plist ( Target / Info ) in generated Xcode project. Newer versions of Unity might add this key automatically; its needed due to privacy concerns, iOS will display confirmation before first usage of microphone.

- when 'Prepare iOS For Recording' is selected - from the manual: 'When selected, the microphone recording APIs are initialised. This makes recording latency lower, though on iPhones it re-routes audio output via earphones only.' ( note: here 'earphones' should be more likely 'earspeaker' )
Since 1.4.1 AudioStream provides 'fix' for this situation with included iOS plugin which requests an audio route override for normal playback to be on speaker/headset; recording uses normal route, i.e. recorded output is on earspeaker/default.


===========================================
General Unity / mobile / FMOD plugin notes:
===========================================

I recommend Unity 5.3.5 and later for mobile applications since previous versions had plethora of varying issues starting with building and ending with ~strike~dragons~/strike~ runtime crashes for unknown reasons.
( Standalone should be fine for runtime from 5.0 except with various quality of life issues in the Editor )

iOS:
 - It is perfectly fine to stay at version 1.08 of the FMOD plugin - previous versions are available at http://www.fmod.org/browse-unity-integration/ . (You can downgrade safely by e.g. removing existing FMOD stuff and importing again as described at the beginning of this readme),
also  due to the special handling of GVR plugin when building. 





===========================================

In case of any questions / suggestion feel free to visit support forum.

Thanks!

Martin

===========================================

V 1.0 062016
- initial version.

V 1.1 082016
- update for FMOD Version 1.08.09 <- Strongly recommended to update, if previous version was used.
- update for Unity 5.4
- improved startup for variable buffer length streams
- improved stream loss detection and recovery
- improved stream finishing for finite streams ( hosted files ) and locally streamed files for AudioStream component
- improved state reporting
- few performance improvements - AudioStream is now even more low profile 

V 1.2 082016
- added option to select any available audio output in the system including non system default one for AudioStreamMinimal

V 1.3 092016
- new AudioSourceOutputDevice component - enables redirection of AudioSource's output buffer to any audio output present in the system
- update for FMOD Version 1.08.11 <- at least this version is needed for AudioSourceOutputDevice to work as it contains a bug fix formerly preventing so.
- fixed tags reporting on track change
- ( refactored common functionality into a new source file )

V 1.4 042017
- new AudioSourceInput component - allows recording audio from any available recording device.
- update for FMOD Version 1.09.03 ( it was not completely necessary, you can stay on any previous version )
- added new demo scenes for each respective functionality type
- few 'quality of life' improvements and usability fixes based on users requests

V 1.4.1 052017
- RAW format support also in the Editor
- iOS recording guide and fixes
- readme updated with general remarks on usability of FMOD and Unity versions
- startup sync to better synchronise user scripts with FMOD initialisation
- Unity audio sample rate compensation for stream sample rate bugfix for AudioStream component
- added AvailableOutputs() also to AudioSourceOutpuDevice allowing its better independent usage

V 1.5 052017
- finally support for Unity spatialisation
- simple minimal 3D demo scene
- few inconsistencies and limitations were resolved in connection to the above
