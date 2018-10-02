// crash at : 5 children sent READY
// then block.

One example of error happened.
Child process :
<img width="1452" alt="image" src="https://user-images.githubusercontent.com/38600346/46380814-2a224980-c67a-11e8-8038-dd93d817e1b1.png">
Parent process:
Sampling process 72841 for 3 seconds with 1 millisecond of run time between samples
Sampling completed, processing symbols...
Analysis of sampling testDemo (pid 72841) every 1 millisecond
Process:         testDemo [72841]
Path:            /Users/WillJia/Library/Developer/Xcode/DerivedData/Pipe-dfzbidcifsljpyaqacfheynbauzg/Build/Products/Debug/testDemo
Load Address:    0x100000000
Identifier:      testDemo
Version:         0
Code Type:       X86-64
Parent Process:  debugserver [72842]

Date/Time:       2018-10-02 19:29:27.390 -0300
Launch Time:     2018-10-02 19:28:28.620 -0300
OS Version:      Mac OS X 10.14 (18A391)
Report Version:  7
Analysis Tool:   /usr/bin/sample

Physical footprint:         5428K
Physical footprint (peak):  5436K
----

Call graph:
2757 Thread_1166804   DispatchQueue_1: com.apple.main-thread  (serial)
+ 2757 start  (in libdyld.dylib) + 1  [0x7fff6842a085]
+   2757 main  (in testDemo) + 910  [0x1000017be]  main.cpp:353
+     2757 waitForReady(int (*) [2])  (in testDemo) + 162  [0x100000d22]  main.cpp:182
+       2757 P_from_C_read(int (*) [2], int, void*, unsigned long)  (in testDemo) + 83  [0x100000b53]  main.cpp:115
+         2757 read  (in libsystem_kernel.dylib) + 10  [0x7fff685648a6]
2757 Thread_1167037
2757 start_wqthread  (in libsystem_pthread.dylib) + 13  [0x1003d4e51]
2757 _pthread_wqthread  (in libsystem_pthread.dylib) + 670  [0x1003d515d]
2757 __workq_kernreturn  (in libsystem_kernel.dylib) + 10  [0x7fff685645be]

Total number in stack (recursive counted multiple, when >=5):

Sort by top of stack, same collapsed (when >= 5):
__workq_kernreturn  (in libsystem_kernel.dylib)        2757
read  (in libsystem_kernel.dylib)        2757

Binary Images:
0x100000000 -        0x100002fff +testDemo (0) <7DBD2D57-A2D7-3F65-9B9E-A1F4D75DF533> /Users/WillJia/Library/Developer/Xcode/DerivedData/Pipe-dfzbidcifsljpyaqacfheynbauzg/Build/Products/Debug/testDemo
0x10000b000 -        0x1000896a7  dyld (625.13) <D6387150-2FB8-3066-868D-72E1B1C43982> /usr/lib/dyld
0x1000ec000 -        0x1000f4ff7 +libBacktraceRecording.dylib (64246.2) <78E47484-9F4B-3C80-9D7A-2354B4046EE1> /Applications/Xcode.app/Contents/Developer/usr/lib/libBacktraceRecording.dylib
0x1000fe000 -        0x100129ff7 +libMainThreadChecker.dylib (64246.2) <8E3CDC3C-82EC-309A-A105-8D99E61CC321> /Applications/Xcode.app/Contents/Developer/usr/lib/libMainThreadChecker.dylib
0x1002f3000 -        0x100324ff3 +libViewDebuggerSupport.dylib (14315.18) <32D897CB-17C4-3A99-9B24-517C72372B61> /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/Library/Debugger/libViewDebuggerSupport.dylib
0x100357000 -        0x10039ffff  libdispatch.dylib (1008.200.78) <CDA4A6FE-4134-3619-8FC4-D6E620146212> /usr/lib/system/introspection/libdispatch.dylib
0x1003d2000 -        0x1003dffff  libsystem_pthread.dylib (330.201.1) <E67AFE84-44C5-3EC9-AC98-AABAC84F45AE> /usr/lib/system/introspection/libsystem_pthread.dylib
0x1003eb000 -        0x100409fff  com.apple.dt.DebugHierarchyFoundation (1.0 - 2) <095560BD-0966-3D7E-9516-894C2D1F93AD> /Applications/Xcode.app/Contents/SharedFrameworks/DebugHierarchyFoundation.framework/Versions/A/DebugHierarchyFoundation
0x7fff372bd000 -     0x7fff374abff3  com.apple.avfoundation (2.0 - 1540.118.2) <1EE74E35-F16B-3034-AEA5-723198E519F8> /System/Library/Frameworks/AVFoundation.framework/Versions/A/AVFoundation
0x7fff374ac000 -     0x7fff3757aff7  com.apple.audio.AVFAudio (1.0 - ???) <727A6D92-D1F2-3179-80D3-51F1481F5A87> /System/Library/Frameworks/AVFoundation.framework/Versions/A/Frameworks/AVFAudio.framework/Versions/A/AVFAudio
0x7fff3757c000 -     0x7fff37687ff3  com.apple.AVKit (1.1 - 445.50.47) <78CE302F-B07D-30FC-83B1-F2B48491F05D> /System/Library/Frameworks/AVKit.framework/Versions/A/AVKit
0x7fff37688000 -     0x7fff37688fff  com.apple.Accelerate (1.11 - Accelerate 1.11) <2C602CED-72CA-37C2-BDF5-31697FC9100B> /System/Library/Frameworks/Accelerate.framework/Versions/A/Accelerate
0x7fff376a0000 -     0x7fff37d40fe3  com.apple.vImage (8.1 - ???) <65912AFB-D4C1-3494-AE97-DDFDAF3BE1EB> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vImage.framework/Versions/A/vImage
0x7fff37d41000 -     0x7fff37fb8fd7  libBLAS.dylib (1243.200.4) <76710990-AE2B-300E-88BB-797ABAD74956> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libBLAS.dylib
0x7fff37fb9000 -     0x7fff3802bfe7  libBNNS.dylib (38.200.5) <5F3A4021-8FF8-30E8-B84A-AA2BD70F4151> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libBNNS.dylib
0x7fff3802c000 -     0x7fff383d2fff  libLAPACK.dylib (1243.200.4) <45722A8A-5788-3C4C-ADD9-1812763FA635> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libLAPACK.dylib
0x7fff383d3000 -     0x7fff383e8ffb  libLinearAlgebra.dylib (1243.200.4) <E923DA33-B142-3A73-A80A-642878D19099> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libLinearAlgebra.dylib
0x7fff383e9000 -     0x7fff383eeff3  libQuadrature.dylib (3.200.2) <6FFAC142-415D-3AF0-BC09-336302F11934> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libQuadrature.dylib
0x7fff383ef000 -     0x7fff3846cffb  libSparse.dylib (79.200.5) <0D7E71A4-10D2-3979-B386-D2426ADAF6D7> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libSparse.dylib
0x7fff3846d000 -     0x7fff38480ffb  libSparseBLAS.dylib (1243.200.4) <00D6FC17-B739-3259-90A4-92AC8BBE03D6> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libSparseBLAS.dylib
0x7fff38481000 -     0x7fff38665ff3  libvDSP.dylib (671.201.1) <716585BD-04D7-30A9-B315-689184275E38> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libvDSP.dylib
0x7fff38666000 -     0x7fff3871bff3  libvMisc.dylib (671.201.1) <EDA66C06-A11F-3EE5-96D5-B20893448899> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/libvMisc.dylib
0x7fff3871c000 -     0x7fff3871cfff  com.apple.Accelerate.vecLib (3.11 - vecLib 3.11) <DADD83A2-550F-3570-8D71-16614C6A4CE0> /System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/vecLib
0x7fff3871d000 -     0x7fff38780ffb  com.apple.Accounts (113 - 113) <516F1A48-D158-3888-91AC-E1C7C3F9CCDD> /System/Library/Frameworks/Accounts.framework/Versions/A/Accounts
0x7fff38783000 -     0x7fff388ccfff  com.apple.AddressBook.framework (11.0 - 1882) <0BA145CD-5D42-31A9-8A41-E56A01589D01> /System/Library/Frameworks/AddressBook.framework/Versions/A/AddressBook
0x7fff388cd000 -     0x7fff396ecff3  com.apple.AppKit (6.9 - 1671) <E1B2CAF1-9231-3B3D-BD9E-B770FE87F407> /System/Library/Frameworks/AppKit.framework/Versions/C/AppKit
0x7fff3973e000 -     0x7fff3973efff  com.apple.ApplicationServices (50.1 - 50.1) <1B71604B-9AC5-3A2F-8CB7-0EFA34A20F12> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/ApplicationServices
0x7fff3973f000 -     0x7fff397aaff7  com.apple.ApplicationServices.ATS (377 - 453.11) <7599E619-EE21-3EB7-875B-AE3B8D3E13BB> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/ATS.framework/Versions/A/ATS
0x7fff39843000 -     0x7fff39962fff  libFontParser.dylib (228.6) <E800074F-62CF-340A-A5A7-B8BE5B560045> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/ATS.framework/Versions/A/Resources/libFontParser.dylib
0x7fff39963000 -     0x7fff399aefff  libFontRegistry.dylib (228.12) <480D472D-C8FB-321D-86EC-2EA6927A97AD> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/ATS.framework/Versions/A/Resources/libFontRegistry.dylib
0x7fff39aaa000 -     0x7fff39aaeff3  com.apple.ColorSyncLegacy (4.13.0 - 1) <90641B6B-D07B-3577-B594-965825544B60> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/ColorSyncLegacy.framework/Versions/A/ColorSyncLegacy
0x7fff39b4b000 -     0x7fff39b9dff3  com.apple.HIServices (1.22 - 627.14.2) <01F309D6-32E7-3C4F-A38B-8206EE3076CC> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/HIServices.framework/Versions/A/HIServices
0x7fff39b9e000 -     0x7fff39bacff3  com.apple.LangAnalysis (1.7.0 - 1.7.0) <67BC5855-B7A3-39E6-B5DD-52B287EB1532> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/LangAnalysis.framework/Versions/A/LangAnalysis
0x7fff39bad000 -     0x7fff39bf9fff  com.apple.print.framework.PrintCore (14.0 - 503.7) <C13BC56A-65F4-35B1-9E33-51FE6F3B06FD> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/PrintCore.framework/Versions/A/PrintCore
0x7fff39bfa000 -     0x7fff39c35ff7  com.apple.QD (3.12 - 407.2) <94A30038-C545-327A-B1C0-E19C79D62BAB> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/QD.framework/Versions/A/QD
0x7fff39c36000 -     0x7fff39c42ff7  com.apple.speech.synthesis.framework (8.0.15 - 8.0.15) <A96C744B-B1AD-32E3-BA72-7A221684BE3F> /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/SpeechSynthesis.framework/Versions/A/SpeechSynthesis
0x7fff39c43000 -     0x7fff39edfff7  com.apple.audio.toolbox.AudioToolbox (1.14 - 1.14) <89D2529D-CF36-3081-A700-70892F888718> /System/Library/Frameworks/AudioToolbox.framework/Versions/A/AudioToolbox
0x7fff39ee1000 -     0x7fff39ee1fff  com.apple.audio.units.AudioUnit (1.14 - 1.14) <8B9A5ADB-E62C-3838-BB5E-AF20CAE449CC> /System/Library/Frameworks/AudioUnit.framework/Versions/A/AudioUnit
0x7fff3a245000 -     0x7fff3a606ff7  com.apple.CFNetwork (974.1 - 974.1) <ACC604FA-5D40-34CE-9206-8091010306B7> /System/Library/Frameworks/CFNetwork.framework/Versions/A/CFNetwork
0x7fff3a61b000 -     0x7fff3a61bfff  com.apple.Carbon (158 - 158) <DAF95685-B793-34EB-96EA-3E292A9E3378> /System/Library/Frameworks/Carbon.framework/Versions/A/Carbon
0x7fff3a61c000 -     0x7fff3a61fffb  com.apple.CommonPanels (1.2.6 - 98) <F1E1C47B-FD1A-30A4-B41B-87BD8B178B56> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/CommonPanels.framework/Versions/A/CommonPanels
0x7fff3a620000 -     0x7fff3a927ff7  com.apple.HIToolbox (2.1.1 - 916.32) <B2ED8B1C-FC3E-3FA0-8F6D-E7A448E6FAA7> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/HIToolbox
0x7fff3a928000 -     0x7fff3a92bffb  com.apple.help (1.3.8 - 66) <4392A63F-9B58-3248-BF73-B46AD3744E6E> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/Help.framework/Versions/A/Help
0x7fff3a92c000 -     0x7fff3a931ff7  com.apple.ImageCapture (9.0 - 1529.7) <364EDC6B-6374-31A7-A637-0044B73F8DBF> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/ImageCapture.framework/Versions/A/ImageCapture
0x7fff3a932000 -     0x7fff3a9c6ff3  com.apple.ink.framework (10.9 - 225) <D6503F37-7EBC-32C1-95CC-A35EFC54E7ED> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/Ink.framework/Versions/A/Ink
0x7fff3a9c7000 -     0x7fff3a9e1fff  com.apple.openscripting (1.7 - 178) <D4A4D130-9C7B-3656-9D58-50F9D09C276E> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/OpenScripting.framework/Versions/A/OpenScripting
0x7fff3aa02000 -     0x7fff3aa03fff  com.apple.print.framework.Print (14.0 - 267.3) <5CD250DF-98AD-30B8-A5D5-47634FF9E74D> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/Print.framework/Versions/A/Print
0x7fff3aa04000 -     0x7fff3aa06ff7  com.apple.securityhi (9.0 - 55006) <C5308CBC-6736-31A7-905B-C635C6D43FDE> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/SecurityHI.framework/Versions/A/SecurityHI
0x7fff3aa07000 -     0x7fff3aa0dff7  com.apple.speech.recognition.framework (6.0.3 - 6.0.3) <1C38B9CB-DD45-3A7B-9D4C-631855A4EE32> /System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/SpeechRecognition.framework/Versions/A/SpeechRecognition
0x7fff3ab34000 -     0x7fff3ab34fff  com.apple.Cocoa (6.11 - 23) <A520D2A3-032B-3C06-81E1-EFDD97C47ACE> /System/Library/Frameworks/Cocoa.framework/Versions/A/Cocoa
0x7fff3ab42000 -     0x7fff3ac0efff  com.apple.ColorSync (4.13.0 - 3340) <0618DA46-5A5E-339D-BB2F-ED66A2BFCCF9> /System/Library/Frameworks/ColorSync.framework/Versions/A/ColorSync
0x7fff3ac0f000 -     0x7fff3ad03ff3  com.apple.contacts (1.0 - 2899) <F5EFA812-6740-3B49-8BB6-26E7A4F391BE> /System/Library/Frameworks/Contacts.framework/Versions/A/Contacts
0x7fff3ada9000 -     0x7fff3ae39fff  com.apple.audio.CoreAudio (4.3.0 - 4.3.0) <5845D43B-BBB5-343B-A164-6F9E2C53CFA3> /System/Library/Frameworks/CoreAudio.framework/Versions/A/CoreAudio
0x7fff3ae9f000 -     0x7fff3aecaff7  com.apple.CoreBluetooth (1.0 - 1) <D2F48E3D-79FC-32D7-B281-658EAD2CC50B> /System/Library/Frameworks/CoreBluetooth.framework/Versions/A/CoreBluetooth
0x7fff3aecb000 -     0x7fff3b26bfeb  com.apple.CoreData (120 - 865.2) <90A5058F-A5AF-311A-81CC-B20C2AC9E85E> /System/Library/Frameworks/CoreData.framework/Versions/A/CoreData
0x7fff3b26c000 -     0x7fff3b355fff  com.apple.CoreDisplay (101.3 - 101.17.6) <4AE5C221-B8E1-3A4F-91E0-96ED5926E82B> /System/Library/Frameworks/CoreDisplay.framework/Versions/A/CoreDisplay
0x7fff3b356000 -     0x7fff3b7a5fff  com.apple.CoreFoundation (6.9 - 1555.10) <4A4C87BC-4C8E-392A-ABEE-824D4074C485> /System/Library/Frameworks/CoreFoundation.framework/Versions/A/CoreFoundation
0x7fff3b7a7000 -     0x7fff3be34fff  com.apple.CoreGraphics (2.0 - 1245.8.4.8) <FFFFEAF0-14DD-38A3-BD68-AA9AB2C672C1> /System/Library/Frameworks/CoreGraphics.framework/Versions/A/CoreGraphics
0x7fff3be36000 -     0x7fff3c15bff7  com.apple.CoreImage (14.0.0 - 700.2.220) <E9E7B27C-C4FD-3AD6-923E-DF7EAE36D1FF> /System/Library/Frameworks/CoreImage.framework/Versions/A/CoreImage
0x7fff3c15c000 -     0x7fff3c1ddff7  com.apple.corelocation (2245.7.106) <1EBFF73E-95B6-31E7-83D5-A75A260D7F25> /System/Library/Frameworks/CoreLocation.framework/Versions/A/CoreLocation
0x7fff3c23d000 -     0x7fff3c4acff7  com.apple.CoreML (1.0 - 1) <E5919684-B63E-3B64-80E2-B73908B99D0F> /System/Library/Frameworks/CoreML.framework/Versions/A/CoreML
0x7fff3c4ad000 -     0x7fff3c5aeff3  com.apple.CoreMedia (1.0 - 2280.133.4) <5E733D6B-B683-3931-9D02-82300A43378D> /System/Library/Frameworks/CoreMedia.framework/Versions/A/CoreMedia
0x7fff3c5af000 -     0x7fff3c611fff  com.apple.CoreMediaIO (900.0 - 5025) <BFB3978A-FDBB-352B-A96D-E8761FC51370> /System/Library/Frameworks/CoreMediaIO.framework/Versions/A/CoreMediaIO
0x7fff3c612000 -     0x7fff3c612fff  com.apple.CoreServices (933 - 933) <B79C910E-93B9-3686-8E72-E0B63083AAE5> /System/Library/Frameworks/CoreServices.framework/Versions/A/CoreServices
0x7fff3c613000 -     0x7fff3c691ffb  com.apple.AE (768 - 768) <E795749D-CE50-3B8C-91A7-8C2618887288> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/AE.framework/Versions/A/AE
0x7fff3c692000 -     0x7fff3c96aff7  com.apple.CoreServices.CarbonCore (1178.11 - 1178.11) <9FBE7BFB-3A81-37AC-8E15-E6F7932BBDC0> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/CarbonCore.framework/Versions/A/CarbonCore
0x7fff3c96b000 -     0x7fff3c9b5ff7  com.apple.DictionaryServices (1.2 - 284.16.3) <D9388630-E7F2-321E-81FF-EBD5F3B47A52> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/DictionaryServices.framework/Versions/A/DictionaryServices
0x7fff3c9b6000 -     0x7fff3c9beffb  com.apple.CoreServices.FSEvents (1239.200.12 - 1239.200.12) <E40A3C4A-79C7-37D8-999B-D1169A06870B> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/FSEvents.framework/Versions/A/FSEvents
0x7fff3c9bf000 -     0x7fff3cb8aff7  com.apple.LaunchServices (933 - 933) <4614A4B4-C358-3460-9FA7-DF8D6C466806> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/LaunchServices.framework/Versions/A/LaunchServices
0x7fff3cb8b000 -     0x7fff3cc2dffb  com.apple.Metadata (10.7.0 - 1191.51) <6B9CCA98-6F68-3908-A7A9-96D3E2AE5968> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/Metadata.framework/Versions/A/Metadata
0x7fff3cc2e000 -     0x7fff3cc79ff7  com.apple.CoreServices.OSServices (933 - 933) <A92C846F-872D-3534-B60E-6CD445A9BAEE> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/OSServices.framework/Versions/A/OSServices
0x7fff3cc7a000 -     0x7fff3cce8ff7  com.apple.SearchKit (1.4.0 - 1.4.0) <C6A34D09-9707-3F28-838F-63B59B8A12D5> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SearchKit.framework/Versions/A/SearchKit
0x7fff3cce9000 -     0x7fff3cd0dffb  com.apple.coreservices.SharedFileList (71.27 - 71.27) <B46A15E0-4C10-3616-BE49-58E07EC463FE> /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/SharedFileList.framework/Versions/A/SharedFileList
0x7fff3d050000 -     0x7fff3d1b5fff  com.apple.CoreText (352.0 - 584.24) <5B55B533-F4DE-32CE-8739-16FFFA1A64F8> /System/Library/Frameworks/CoreText.framework/Versions/A/CoreText
0x7fff3d1b6000 -     0x7fff3d1f3fff  com.apple.CoreVideo (1.8 - 0.0) <C7BB7D0F-3AF2-3046-A387-A802BCA52A3A> /System/Library/Frameworks/CoreVideo.framework/Versions/A/CoreVideo
0x7fff3d1f4000 -     0x7fff3d28affb  com.apple.framework.CoreWLAN (13.0 - 1370.8) <19E41424-B956-34DF-AE02-9822308FA3DC> /System/Library/Frameworks/CoreWLAN.framework/Versions/A/CoreWLAN
0x7fff3d41a000 -     0x7fff3d425ffb  com.apple.DirectoryService.Framework (10.14 - 207.200.4) <222097B7-D721-3F27-9798-ACC95E73F233> /System/Library/Frameworks/DirectoryService.framework/Versions/A/DirectoryService
0x7fff3d426000 -     0x7fff3d4e0ff7  com.apple.DiscRecording (9.0.3 - 9030.4.5) <55E40DE0-500B-3AC4-81BA-4A54BC04740C> /System/Library/Frameworks/DiscRecording.framework/Versions/A/DiscRecording
0x7fff3d507000 -     0x7fff3d50cfff  com.apple.DiskArbitration (2.7 - 2.7) <C53C1905-9BCF-3AE8-8BB3-C8A2C7DB7D25> /System/Library/Frameworks/DiskArbitration.framework/Versions/A/DiskArbitration
0x7fff3d6d5000 -     0x7fff3daa3fff  com.apple.Foundation (6.9 - 1555.10) <0CCAF9AF-F7AF-3174-98D4-6C188B1079CC> /System/Library/Frameworks/Foundation.framework/Versions/C/Foundation
0x7fff3daa5000 -     0x7fff3dacfff7  com.apple.GLKit (1.0 - 101) <9D54B1E5-D6AC-3F68-8261-954127345FDD> /System/Library/Frameworks/GLKit.framework/Versions/A/GLKit
0x7fff3db14000 -     0x7fff3db44ff3  com.apple.GSS (4.0 - 2.0) <74ACB1A1-A5A4-3180-AC00-688C94AA4434> /System/Library/Frameworks/GSS.framework/Versions/A/GSS
0x7fff3dc5d000 -     0x7fff3dd66ff3  com.apple.Bluetooth (6.0.8 - 6.0.8f6) <6CB8A08E-1154-3333-83CC-2A939AC94562> /System/Library/Frameworks/IOBluetooth.framework/Versions/A/IOBluetooth
0x7fff3ddc8000 -     0x7fff3de59fff  com.apple.framework.IOKit (2.0.2 - 1483.201.1) <DA4ED91F-2CC9-3CFD-9200-9D5D31EEE4F3> /System/Library/Frameworks/IOKit.framework/Versions/A/IOKit
0x7fff3de5b000 -     0x7fff3de65ff7  com.apple.IOSurface (255.1 - 255.1) <538F0257-A408-36AF-AB1E-1D7037D6359E> /System/Library/Frameworks/IOSurface.framework/Versions/A/IOSurface
0x7fff3de66000 -     0x7fff3debbff7  com.apple.ImageCaptureCore (1.0 - 1529.7) <3A387CA8-BC6E-3554-91FB-42C074EECDA7> /System/Library/Frameworks/ImageCaptureCore.framework/Versions/A/ImageCaptureCore
0x7fff3debc000 -     0x7fff3e050ff7  com.apple.ImageIO.framework (3.3.0 - 1796.5.4.1) <9D078F50-BB75-3D04-8636-3FDDAB9C95DA> /System/Library/Frameworks/ImageIO.framework/Versions/A/ImageIO
0x7fff3e051000 -     0x7fff3e055ffb  libGIF.dylib (1796.5.4.1) <93AD6FB9-03BA-350E-AF98-D371A2BFD58F> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libGIF.dylib
0x7fff3e056000 -     0x7fff3e13bfef  libJP2.dylib (1796.5.4.1) <3780EB9B-5219-385D-9472-17B0397697A5> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libJP2.dylib
0x7fff3e13c000 -     0x7fff3e161ff7  libJPEG.dylib (1796.5.4.1) <83CA8BEB-34BD-3B58-A704-C6A875984FAD> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libJPEG.dylib
0x7fff3e434000 -     0x7fff3e45afe7  libPng.dylib (1796.5.4.1) <9F30FA63-8AB2-3646-A6A8-FCE9F8436C35> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libPng.dylib
0x7fff3e45b000 -     0x7fff3e45dff7  libRadiance.dylib (1796.5.4.1) <2C07887C-0584-3538-A9EC-3988AA5B234B> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libRadiance.dylib
0x7fff3e45e000 -     0x7fff3e4acfff  libTIFF.dylib (1796.5.4.1) <F420B0DC-D0F7-3DD5-9E17-00462441635C> /System/Library/Frameworks/ImageIO.framework/Versions/A/Resources/libTIFF.dylib
0x7fff3e7a8000 -     0x7fff3f52aff7  com.apple.JavaScriptCore (14606 - 14606.1.36.1.9) <7FF80E53-3D6B-33BF-9538-A263513475EC> /System/Library/Frameworks/JavaScriptCore.framework/Versions/A/JavaScriptCore
0x7fff3f542000 -     0x7fff3f55bfff  com.apple.Kerberos (3.0 - 1) <8BE3D524-257D-3663-A937-F1AC76BDF4D9> /System/Library/Frameworks/Kerberos.framework/Versions/A/Kerberos
0x7fff3f55c000 -     0x7fff3f591ffb  com.apple.LDAPFramework (2.4.28 - 194.5) <DC361FB9-4B59-311E-8CC5-07FF9A9C673F> /System/Library/Frameworks/LDAP.framework/Versions/A/LDAP
0x7fff3f616000 -     0x7fff3f816ff7  com.apple.MapKit (1.0 - 1832.20.2.5.89) <2F530338-22D9-3CBF-86C9-A9A007154C2A> /System/Library/Frameworks/MapKit.framework/Versions/A/MapKit
0x7fff3f818000 -     0x7fff3f822fff  com.apple.MediaAccessibility (1.0 - 114.4) <29D89F2B-6254-3D0D-BD0C-8472FCA373F4> /System/Library/Frameworks/MediaAccessibility.framework/Versions/A/MediaAccessibility
0x7fff3f838000 -     0x7fff3f8dbfff  com.apple.MediaPlayer (1.0 - 1.0) <8D6F9AF7-E77E-369F-92E4-709F916198E1> /System/Library/Frameworks/MediaPlayer.framework/Versions/A/MediaPlayer
0x7fff3f8dc000 -     0x7fff3ff78ff7  com.apple.MediaToolbox (1.0 - 2280.133.4) <FB1C3DD9-A91B-3952-A892-9F009B854F8F> /System/Library/Frameworks/MediaToolbox.framework/Versions/A/MediaToolbox
0x7fff3ff7a000 -     0x7fff4000dfff  com.apple.Metal (157.55 - 157.55) <49CD402F-20CB-3930-B997-BBDC495ABF64> /System/Library/Frameworks/Metal.framework/Versions/A/Metal
0x7fff4000f000 -     0x7fff40029ff3  com.apple.MetalKit (1.0 - 113) <8949A0FA-337E-3C28-94D1-35853D69761B> /System/Library/Frameworks/MetalKit.framework/Versions/A/MetalKit
0x7fff4002a000 -     0x7fff4004aff7  com.apple.MetalPerformanceShaders.MPSCore (1.0 - 1) <9A841A76-43BC-3220-A4DA-99137C42A0BC> /System/Library/Frameworks/MetalPerformanceShaders.framework/Frameworks/MPSCore.framework/Versions/A/MPSCore
0x7fff4004b000 -     0x7fff400c8fef  com.apple.MetalPerformanceShaders.MPSImage (1.0 - 1) <C469D1E5-F621-3E56-87AC-1BD889664FA3> /System/Library/Frameworks/MetalPerformanceShaders.framework/Frameworks/MPSImage.framework/Versions/A/MPSImage
0x7fff400c9000 -     0x7fff400f1fff  com.apple.MetalPerformanceShaders.MPSMatrix (1.0 - 1) <8C57A3A2-8EBB-3401-87FC-368D1BE6DAAC> /System/Library/Frameworks/MetalPerformanceShaders.framework/Frameworks/MPSMatrix.framework/Versions/A/MPSMatrix
0x7fff400f2000 -     0x7fff40219ff7  com.apple.MetalPerformanceShaders.MPSNeuralNetwork (1.0 - 1) <CE3201A3-4ACE-3E79-990B-8987C576B31B> /System/Library/Frameworks/MetalPerformanceShaders.framework/Frameworks/MPSNeuralNetwork.framework/Versions/A/MPSNeuralNetwork
0x7fff4021a000 -     0x7fff40235ff7  com.apple.MetalPerformanceShaders.MPSRayIntersector (1.0 - 1) <8F02CFCA-41E1-3194-915F-3106E8B48B32> /System/Library/Frameworks/MetalPerformanceShaders.framework/Frameworks/MPSRayIntersector.framework/Versions/A/MPSRayIntersector
0x7fff40236000 -     0x7fff40236ff7  com.apple.MetalPerformanceShaders.MetalPerformanceShaders (1.0 - 1) <8B715D78-8357-38F4-A03C-926EE967CE71> /System/Library/Frameworks/MetalPerformanceShaders.framework/Versions/A/MetalPerformanceShaders
0x7fff40237000 -     0x7fff413b4fff  com.apple.ModelIO (1.0 - 1) <CB9C3B50-5341-36F0-91B3-AB5B2922D06D> /System/Library/Frameworks/ModelIO.framework/Versions/A/ModelIO
0x7fff41435000 -     0x7fff41441ffb  com.apple.NetFS (6.0 - 4.0) <529E29A9-5E77-3A8C-A982-CF55F949FE5D> /System/Library/Frameworks/NetFS.framework/Versions/A/NetFS
0x7fff43f01000 -     0x7fff43f5aff7  com.apple.opencl (2.12.1 - 2.12.1) <3EAE5BC8-E948-3926-9319-9DAC2A8B5484> /System/Library/Frameworks/OpenCL.framework/Versions/A/OpenCL
0x7fff43f5b000 -     0x7fff43f77ff7  com.apple.CFOpenDirectory (10.14 - 207.200.4) <7E4EFF02-2596-31E6-88DE-29C89E2837E4> /System/Library/Frameworks/OpenDirectory.framework/Versions/A/Frameworks/CFOpenDirectory.framework/Versions/A/CFOpenDirectory
0x7fff43f78000 -     0x7fff43f84ffb  com.apple.OpenDirectory (10.14 - 207.200.4) <52A3918E-0F7A-33FD-87EE-21A37B37D13B> /System/Library/Frameworks/OpenDirectory.framework/Versions/A/OpenDirectory
0x7fff448e7000 -     0x7fff448e9fff  libCVMSPluginSupport.dylib (17.0.37) <38A18A32-BBF2-3A0F-AE37-51734B6CA91A> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCVMSPluginSupport.dylib
0x7fff448ea000 -     0x7fff448efff3  libCoreFSCache.dylib (163.20) <BF8F04DD-C1A1-3D2A-BF3F-639FE907E28D> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreFSCache.dylib
0x7fff448f0000 -     0x7fff448f4fff  libCoreVMClient.dylib (163.20) <45A2C724-F3D1-316A-9A41-CAB8E2A390EC> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreVMClient.dylib
0x7fff448f5000 -     0x7fff448fdffb  libGFXShared.dylib (17.0.37) <267B40DF-2939-3D76-89FA-E8DBDEE96D92> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGFXShared.dylib
0x7fff448fe000 -     0x7fff44909fff  libGL.dylib (17.0.37) <2E25A83B-B560-34A1-B474-3027C8B75BA4> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
0x7fff4490a000 -     0x7fff44944fef  libGLImage.dylib (17.0.37) <49C5F799-66E5-3A81-AF88-948DD0E583FA> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLImage.dylib
0x7fff44ab8000 -     0x7fff44af5fff  libGLU.dylib (17.0.37) <79555E42-B816-3106-8FA0-FC14A54AE8B3> /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib
0x7fff454a5000 -     0x7fff454b4ff3  com.apple.opengl (17.0.37 - 17.0.37) <FA76EAA6-D035-3444-87F5-DD95446D651D> /System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL
0x7fff45836000 -     0x7fff45980fff  com.apple.QTKit (7.7.3 - 3034) <D612DC6C-0AA8-3D41-9E17-E8219984FC65> /System/Library/Frameworks/QTKit.framework/Versions/A/QTKit
0x7fff45981000 -     0x7fff45bdcfff  com.apple.imageKit (3.0 - 1067) <A43B90AB-8FCB-35BF-996A-CEB28B67EEB5> /System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/ImageKit.framework/Versions/A/ImageKit
0x7fff45bdd000 -     0x7fff45cc9fff  com.apple.PDFKit (1.0 - 737.3) <F6981903-7259-3D89-B70E-855F970D84E7> /System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/PDFKit.framework/Versions/A/PDFKit
0x7fff45cca000 -     0x7fff461e0ff7  com.apple.QuartzComposer (5.1 - 370) <AA2ED670-1970-3888-B7DB-D11192EBF6BB> /System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/QuartzComposer.framework/Versions/A/QuartzComposer
0x7fff461e1000 -     0x7fff46207ff3  com.apple.quartzfilters (1.10.0 - 83) <06F25528-5474-39BF-BCD4-DD6B3203EA3C> /System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/QuartzFilters.framework/Versions/A/QuartzFilters
0x7fff46208000 -     0x7fff4630eff7  com.apple.QuickLookUIFramework (5.0 - 775) <41F1FDD0-C99A-36D3-AC3A-A5E604D77F63> /System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/QuickLookUI.framework/Versions/A/QuickLookUI
0x7fff4630f000 -     0x7fff4630ffff  com.apple.quartzframework (1.5 - 23) <103A742C-50F3-3A4A-B787-FDD35F36B6F1> /System/Library/Frameworks/Quartz.framework/Versions/A/Quartz
0x7fff46310000 -     0x7fff46566fff  com.apple.QuartzCore (1.11 - 693.16.4.2) <2C9E3279-3F97-3440-B937-E5FE888232E2> /System/Library/Frameworks/QuartzCore.framework/Versions/A/QuartzCore
0x7fff46567000 -     0x7fff465c0ff7  com.apple.QuickLookFramework (5.0 - 775) <A4CA709A-2828-3F04-8786-7FAC8A95B98B> /System/Library/Frameworks/QuickLook.framework/Versions/A/QuickLook
0x7fff46787000 -     0x7fff4679fffb  com.apple.SafariServices.framework (14606 - 14606.1.36.1.9) <99E7035E-6B88-3F4D-A042-A24BEDCB0666> /System/Library/Frameworks/SafariServices.framework/Versions/A/SafariServices
0x7fff467a0000 -     0x7fff46d7bff7  com.apple.SceneKit (1.0 - 470) <1A60111F-7E7B-30F0-9261-0C9118192C92> /System/Library/Frameworks/SceneKit.framework/Versions/A/SceneKit
0x7fff46db4000 -     0x7fff470dafff  com.apple.security (7.0 - 58286.200.222) <AEB638D9-BFE9-319E-A70B-557ACF41117A> /System/Library/Frameworks/Security.framework/Versions/A/Security
0x7fff470db000 -     0x7fff4716afff  com.apple.securityfoundation (6.0 - 55185.200.14) <770D67D1-3DA6-3FD3-8531-376712BA4F60> /System/Library/Frameworks/SecurityFoundation.framework/Versions/A/SecurityFoundation
0x7fff4716b000 -     0x7fff4719bffb  com.apple.securityinterface (10.0 - 55109.200.8) <8BDA8A18-C4EB-3267-96AB-0C2F2321866D> /System/Library/Frameworks/SecurityInterface.framework/Versions/A/SecurityInterface
0x7fff4719c000 -     0x7fff471a0ff3  com.apple.xpc.ServiceManagement (1.0 - 1) <20DB899D-3BAF-36FD-86A6-F66A82074607> /System/Library/Frameworks/ServiceManagement.framework/Versions/A/ServiceManagement
0x7fff4755d000 -     0x7fff475cdff3  com.apple.SystemConfiguration (1.17 - 1.17) <EED5BC9B-CE8D-343C-BCDC-04A79F704828> /System/Library/Frameworks/SystemConfiguration.framework/Versions/A/SystemConfiguration
0x7fff4782e000 -     0x7fff47b90ff7  com.apple.VideoToolbox (1.0 - 2280.133.4) <468A9F6D-33AB-31D3-A8A3-A6A432033C9E> /System/Library/Frameworks/VideoToolbox.framework/Versions/A/VideoToolbox
0x7fff47e9e000 -     0x7fff4842cff7  libwebrtc.dylib (7606.1.36.1.9) <9D8EADA7-921A-377C-8B0F-5A1D42AC43A7> /System/Library/Frameworks/WebKit.framework/Versions/A/Frameworks/WebCore.framework/Versions/A/Frameworks/libwebrtc.dylib
0x7fff4842d000 -     0x7fff49cadff7  com.apple.WebCore (14606 - 14606.1.36.1.9) <099B8FA5-D49D-3C7E-B40A-613CA6E7B769> /System/Library/Frameworks/WebKit.framework/Versions/A/Frameworks/WebCore.framework/Versions/A/WebCore
0x7fff49cae000 -     0x7fff49e9dffb  com.apple.WebKitLegacy (14606 - 14606.1.36.1.9) <60C1D461-49C9-3B8B-9BD4-B95F1D18335F> /System/Library/Frameworks/WebKit.framework/Versions/A/Frameworks/WebKitLegacy.framework/Versions/A/WebKitLegacy
0x7fff49e9e000 -     0x7fff4a39bfff  com.apple.WebKit (14606 - 14606.1.36.1.9) <5E4AF277-D207-3647-9D5C-A6F1543A2D4D> /System/Library/Frameworks/WebKit.framework/Versions/A/WebKit
0x7fff4a832000 -     0x7fff4a8d7ff7  com.apple.APFS (1.0 - 1) <CBE5EE83-7A5F-3C10-93FF-F6DA84DFB875> /System/Library/PrivateFrameworks/APFS.framework/Versions/A/APFS
0x7fff4ae60000 -     0x7fff4ae66ff3  com.apple.accessibility.AXCoreUtilities (1.0 - 1) <A10AB2DC-7C65-3FC0-8416-246003D158A6> /System/Library/PrivateFrameworks/AXCoreUtilities.framework/Versions/A/AXCoreUtilities
0x7fff4b19b000 -     0x7fff4b2f7ffb  com.apple.AddressBook.core (1.0 - 1) <68F1FB1D-2198-3FC6-AC27-94BD7E058058> /System/Library/PrivateFrameworks/AddressBookCore.framework/Versions/A/AddressBookCore
0x7fff4b313000 -     0x7fff4b314ff3  com.apple.AggregateDictionary (1.0 - 1) <1DEBBE36-8945-3AD8-BD48-2850AD845711> /System/Library/PrivateFrameworks/AggregateDictionary.framework/Versions/A/AggregateDictionary
0x7fff4b6c0000 -     0x7fff4b809ff3  com.apple.AnnotationKit (1.0 - 232.3.27) <2F217C3B-CF60-355B-97B4-AF7CB62CA822> /System/Library/PrivateFrameworks/AnnotationKit.framework/Versions/A/AnnotationKit
0x7fff4b8ed000 -     0x7fff4b90efff  com.apple.AppSupportUI (1.0 - ???) <A35A8A40-4A03-3302-A2CD-03BDD6C38B74> /System/Library/PrivateFrameworks/AppSupportUI.framework/Versions/A/AppSupportUI
0x7fff4b90f000 -     0x7fff4b93bff7  com.apple.framework.Apple80211 (13.0 - 1375.14) <79EBF155-EAB2-37EE-BF8C-57BC453217B1> /System/Library/PrivateFrameworks/Apple80211.framework/Versions/A/Apple80211
0x7fff4bc17000 -     0x7fff4bc26fcf  com.apple.AppleFSCompression (96.200.3 - 1.0) <E093776E-C367-3CCF-BFD5-623476A89E9A> /System/Library/PrivateFrameworks/AppleFSCompression.framework/Versions/A/AppleFSCompression
0x7fff4bd24000 -     0x7fff4bd2ffff  com.apple.AppleIDAuthSupport (1.0 - 1) <5362D9AD-A2AE-3436-97CE-C353124504E5> /System/Library/PrivateFrameworks/AppleIDAuthSupport.framework/Versions/A/AppleIDAuthSupport
0x7fff4bd70000 -     0x7fff4bdb9ff3  com.apple.AppleJPEG (1.0 - 1) <9A690E6E-F987-3660-BED6-B1A4D1906B6C> /System/Library/PrivateFrameworks/AppleJPEG.framework/Versions/A/AppleJPEG
0x7fff4bdba000 -     0x7fff4bdcaff3  com.apple.AppleLDAP (10.14 - 46.200.2) <1CA0C188-D060-3B80-84A1-6FA90812AF11> /System/Library/PrivateFrameworks/AppleLDAP.framework/Versions/A/AppleLDAP
0x7fff4bfe3000 -     0x7fff4c003ff7  com.apple.aps.framework (4.0 - 4.0) <C1F1D153-CB1A-3C12-93E5-CDD38F0481E3> /System/Library/PrivateFrameworks/ApplePushService.framework/Versions/A/ApplePushService
0x7fff4c004000 -     0x7fff4c008ff7  com.apple.AppleSRP (5.0 - 1) <B8E2BEC9-FAFB-3E26-BF26-E2E58C545006> /System/Library/PrivateFrameworks/AppleSRP.framework/Versions/A/AppleSRP
0x7fff4c009000 -     0x7fff4c031ff7  com.apple.applesauce (1.0 - ???) <60BB16D6-DE7E-356A-B9DE-F73EE179934A> /System/Library/PrivateFrameworks/AppleSauce.framework/Versions/A/AppleSauce
0x7fff4c0f8000 -     0x7fff4c0fbff7  com.apple.AppleSystemInfo (3.1.5 - 3.1.5) <2449197F-DF0D-32BB-B0B1-D78855528692> /System/Library/PrivateFrameworks/AppleSystemInfo.framework/Versions/A/AppleSystemInfo
0x7fff4c0fc000 -     0x7fff4c14cfff  com.apple.AppleVAFramework (5.0.44 - 5.0.44) <F7B8CD3A-8671-3B2C-B67C-CE39C1442207> /System/Library/PrivateFrameworks/AppleVA.framework/Versions/A/AppleVA
0x7fff4c197000 -     0x7fff4c1adffb  com.apple.AssertionServices (1.0 - 1) <8FB0D908-6C46-3399-92D6-4E7D4B5F4F19> /System/Library/PrivateFrameworks/AssertionServices.framework/Versions/A/AssertionServices
0x7fff4c4dd000 -     0x7fff4c780ffb  com.apple.AuthKit (1.0 - 1) <ED375339-69F6-34AE-825D-F16BF0618E3E> /System/Library/PrivateFrameworks/AuthKit.framework/Versions/A/AuthKit
0x7fff4c951000 -     0x7fff4c95aff3  com.apple.coreservices.BackgroundTaskManagement (1.0 - 57.1) <972F41B3-7DF7-3BF1-ACCA-A093A4328ADF> /System/Library/PrivateFrameworks/BackgroundTaskManagement.framework/Versions/A/BackgroundTaskManagement
0x7fff4c95b000 -     0x7fff4c9fdff7  com.apple.backup.framework (1.10 - ???) <46534B04-DD0E-357B-9CB5-F88AAC6AF4ED> /System/Library/PrivateFrameworks/Backup.framework/Versions/A/Backup
0x7fff4c9fe000 -     0x7fff4ca6fffb  com.apple.BaseBoard (360.18.4 - 360.18.4) <709EF03C-5BCE-3F47-BD58-A48C1F9378A5> /System/Library/PrivateFrameworks/BaseBoard.framework/Versions/A/BaseBoard
0x7fff4ca78000 -     0x7fff4ca7eff3  com.apple.BezelServicesFW (317 - 317) <44601C3E-4808-38A4-A554-71F36000B003> /System/Library/PrivateFrameworks/BezelServices.framework/Versions/A/BezelServices
0x7fff4caf8000 -     0x7fff4cb34ffb  com.apple.bom (14.0 - 197) <8BD14107-DB70-3800-9377-618CA230B40A> /System/Library/PrivateFrameworks/Bom.framework/Versions/A/Bom
0x7fff4d202000 -     0x7fff4d230fff  com.apple.CalendarAgentLink (8.0 - 250) <3741CC99-814F-3E74-97A7-B658D8DB5C72> /System/Library/PrivateFrameworks/CalendarAgentLink.framework/Versions/A/CalendarAgentLink
0x7fff4d911000 -     0x7fff4d95efff  com.apple.ChunkingLibrary (194 - 194) <13F1F769-E8E7-372A-8F0B-2BB4B7753248> /System/Library/PrivateFrameworks/ChunkingLibrary.framework/Versions/A/ChunkingLibrary
0x7fff4e61e000 -     0x7fff4e627fff  com.apple.CommonAuth (4.0 - 2.0) <7105F266-35C3-3582-9383-A2A9D7184A7B> /System/Library/PrivateFrameworks/CommonAuth.framework/Versions/A/CommonAuth
0x7fff4e63b000 -     0x7fff4e651ffb  com.apple.commonutilities (8.0 - 900) <BE71A0AD-7ED9-3B2A-BF7D-DA7841640FE0> /System/Library/PrivateFrameworks/CommonUtilities.framework/Versions/A/CommonUtilities
0x7fff4e905000 -     0x7fff4e96fff7  com.apple.AddressBook.ContactsFoundation (8.0 - ???) <2A910333-619F-3A27-B40E-0A4BF0F75AA8> /System/Library/PrivateFrameworks/ContactsFoundation.framework/Versions/A/ContactsFoundation
0x7fff4e970000 -     0x7fff4e994ffb  com.apple.contacts.ContactsPersistence (1.0 - ???) <1700A26A-3951-3B33-B503-B0272BF33C3D> /System/Library/PrivateFrameworks/ContactsPersistence.framework/Versions/A/ContactsPersistence
0x7fff4ead7000 -     0x7fff4eeaefef  com.apple.CoreAUC (273.0.0 - 273.0.0) <288EC7ED-A86A-30D0-ADE2-56C33CD93AA8> /System/Library/PrivateFrameworks/CoreAUC.framework/Versions/A/CoreAUC
0x7fff4eeaf000 -     0x7fff4eee0fff  com.apple.CoreAVCHD (6.0.0 - 6000.4.1) <507AC58B-4527-353B-99CB-67FF183BD4D5> /System/Library/PrivateFrameworks/CoreAVCHD.framework/Versions/A/CoreAVCHD
0x7fff4ef77000 -     0x7fff4efc9ffb  com.apple.corebrightness (1.0 - 1) <84B0814D-7DE5-3518-9BA3-2DA235E0EA35> /System/Library/PrivateFrameworks/CoreBrightness.framework/Versions/A/CoreBrightness
0x7fff4f10d000 -     0x7fff4f116fff  com.apple.frameworks.CoreDaemon (1.3 - 1.3) <8D971ACD-6A26-30A9-9C5B-BCBF60A661F1> /System/Library/PrivateFrameworks/CoreDaemon.framework/Versions/B/CoreDaemon
0x7fff4f324000 -     0x7fff4f337fff  com.apple.CoreEmoji (1.0 - 69.15.9) <011E7853-BDD6-3197-BA8D-D6B977EF56EB> /System/Library/PrivateFrameworks/CoreEmoji.framework/Versions/A/CoreEmoji
0x7fff4f4fd000 -     0x7fff4f5f1ff7  com.apple.CoreHandwriting (161 - 1.2) <0BD558D9-387B-34BA-8FAA-F1F75F1F9F01> /System/Library/PrivateFrameworks/CoreHandwriting.framework/Versions/A/CoreHandwriting
0x7fff4f7b4000 -     0x7fff4f7caffb  com.apple.CoreMediaAuthoring (2.2 - 958) <FD761818-0B54-3DA6-B41C-20263BC2EDAE> /System/Library/PrivateFrameworks/CoreMediaAuthoring.framework/Versions/A/CoreMediaAuthoring
0x7fff4f90d000 -     0x7fff4f97fff7  com.apple.CoreNLP (1.0 - 130.15.22) <401F5284-A984-32A1-A547-CC8156381070> /System/Library/PrivateFrameworks/CoreNLP.framework/Versions/A/CoreNLP
0x7fff4fb02000 -     0x7fff4fb06ff7  com.apple.CoreOptimization (1.0 - 1) <AEF88F43-C928-3DCB-95D6-C6706B565422> /System/Library/PrivateFrameworks/CoreOptimization.framework/Versions/A/CoreOptimization
0x7fff4fb07000 -     0x7fff4fb94ff7  com.apple.CorePDF (4.0 - 414) <28DEBFFB-BABE-3493-8230-12CE3E5EC1E3> /System/Library/PrivateFrameworks/CorePDF.framework/Versions/A/CorePDF
0x7fff4fc3a000 -     0x7fff4fc42ffb  com.apple.CorePhoneNumbers (1.0 - 1) <F47CA56F-6760-3282-BFD8-C8C8D2C33ECF> /System/Library/PrivateFrameworks/CorePhoneNumbers.framework/Versions/A/CorePhoneNumbers
0x7fff4fc43000 -     0x7fff4fc9ffff  com.apple.CorePrediction (1.0 - 1) <BD34AB8C-8899-3BB1-95A2-0A2A1C901ADC> /System/Library/PrivateFrameworks/CorePrediction.framework/Versions/A/CorePrediction
0x7fff501c7000 -     0x7fff50255ff7  com.apple.CoreSymbolication (10.0 - 64235.3.1) <912C63C0-473B-3352-A255-60F7CA3FE3F2> /System/Library/PrivateFrameworks/CoreSymbolication.framework/Versions/A/CoreSymbolication
0x7fff502e5000 -     0x7fff50411fff  com.apple.coreui (2.1 - 498.46) <05F9736C-5A62-33B3-9607-551A332AEF28> /System/Library/PrivateFrameworks/CoreUI.framework/Versions/A/CoreUI
0x7fff50412000 -     0x7fff50591ffb  com.apple.CoreUtils (5.7 - 570.70) <2554BA12-16A2-399F-A13A-E5C8EB4FC1EC> /System/Library/PrivateFrameworks/CoreUtils.framework/Versions/A/CoreUtils
0x7fff505e8000 -     0x7fff5064bffb  com.apple.framework.CoreWiFi (13.0 - 1370.8) <5C6ACF32-14D3-35FD-8A4A-629521090F41> /System/Library/PrivateFrameworks/CoreWiFi.framework/Versions/A/CoreWiFi
0x7fff5064c000 -     0x7fff5065dffb  com.apple.CrashReporterSupport (10.13 - 938.23) <36754BB2-680F-36AE-A5DE-548B4F41F0AE> /System/Library/PrivateFrameworks/CrashReporterSupport.framework/Versions/A/CrashReporterSupport
0x7fff506e0000 -     0x7fff506efff3  com.apple.framework.DFRFoundation (1.0 - 210) <61EF0583-E946-3201-932D-7D117BC62CB2> /System/Library/PrivateFrameworks/DFRFoundation.framework/Versions/A/DFRFoundation
0x7fff506f0000 -     0x7fff506f4ff7  com.apple.DSExternalDisplay (3.1 - 380) <B6B26BB3-2DC9-34D0-817E-EB612432EC96> /System/Library/PrivateFrameworks/DSExternalDisplay.framework/Versions/A/DSExternalDisplay
0x7fff50777000 -     0x7fff507eeffb  com.apple.datadetectorscore (7.0 - 590.24) <2D4CFF51-BCD4-3D08-AE73-AB2B8BEC8659> /System/Library/PrivateFrameworks/DataDetectorsCore.framework/Versions/A/DataDetectorsCore
0x7fff5083c000 -     0x7fff5087dfff  com.apple.DebugSymbols (185 - 185) <01F561DA-4724-32FD-B2C7-6436F4CEB980> /System/Library/PrivateFrameworks/DebugSymbols.framework/Versions/A/DebugSymbols
0x7fff5087e000 -     0x7fff509d7ff7  com.apple.desktopservices (1.13 - ???) <053D3A96-9263-3242-8625-101DDB9350DE> /System/Library/PrivateFrameworks/DesktopServicesPriv.framework/Versions/A/DesktopServicesPriv
0x7fff50bdc000 -     0x7fff50ca0fff  com.apple.DiskManagement (12.0 - 1530) <F844A618-613A-3609-9C31-621D92FB75DD> /System/Library/PrivateFrameworks/DiskManagement.framework/Versions/A/DiskManagement
0x7fff50ca1000 -     0x7fff50ca5ff7  com.apple.DisplayServicesFW (3.1 - 380) <EE27909F-7790-3438-ACA4-3993233A67B8> /System/Library/PrivateFrameworks/DisplayServices.framework/Versions/A/DisplayServices
0x7fff50d46000 -     0x7fff50d49fff  com.apple.EFILogin (2.0 - 2) <8FCA68D2-CEA5-39F6-B222-AC31FCF79D1D> /System/Library/PrivateFrameworks/EFILogin.framework/Versions/A/EFILogin
0x7fff5152e000 -     0x7fff51860fff  com.apple.vision.EspressoFramework (1.0 - 120) <673D7C7E-62BC-3B81-8A32-B9AC3FD13A92> /System/Library/PrivateFrameworks/Espresso.framework/Versions/A/Espresso
0x7fff51a1b000 -     0x7fff51e43fff  com.apple.vision.FaceCore (3.3.4 - 3.3.4) <CCBC466A-1AD4-3B0B-80B2-D6CFCBB37FC0> /System/Library/PrivateFrameworks/FaceCore.framework/Versions/A/FaceCore
0x7fff56e0b000 -     0x7fff56e10ff7  com.apple.GPUWrangler (3.22.9 - 3.22.9) <A7FF28DC-3576-3E53-AFAF-0E29CB45E9AE> /System/Library/PrivateFrameworks/GPUWrangler.framework/Versions/A/GPUWrangler
0x7fff571c0000 -     0x7fff571e5ff7  com.apple.GenerationalStorage (2.0 - 285.101) <089301DF-60C9-3BED-9357-2F91336C1579> /System/Library/PrivateFrameworks/GenerationalStorage.framework/Versions/A/GenerationalStorage
0x7fff571fe000 -     0x7fff57c2cfff  com.apple.GeoServices (1.0 - 1364.20.2.5.70) <8662E9B6-2249-359D-B7A9-FE8BE9B55B51> /System/Library/PrivateFrameworks/GeoServices.framework/Versions/A/GeoServices
0x7fff57c6f000 -     0x7fff57c7efff  com.apple.GraphVisualizer (1.0 - 5) <C7040CD7-6CAB-3878-B29E-21F1665341D0> /System/Library/PrivateFrameworks/GraphVisualizer.framework/Versions/A/GraphVisualizer
0x7fff57c7f000 -     0x7fff57c8cfff  com.apple.GraphicsServices (1.0 - 1.0) <F099E6ED-E08D-3F37-B381-0DF3109B27AA> /System/Library/PrivateFrameworks/GraphicsServices.framework/Versions/A/GraphicsServices
0x7fff57d65000 -     0x7fff57dd9fff  com.apple.Heimdal (4.0 - 2.0) <793E1D31-6166-37F2-A989-F98FE1706E5D> /System/Library/PrivateFrameworks/Heimdal.framework/Versions/A/Heimdal
0x7fff591b5000 -     0x7fff591bcffb  com.apple.IOAccelerator (400.24 - 400.24) <01551ED8-6AE1-307D-A3F0-DCA85FAA5210> /System/Library/PrivateFrameworks/IOAccelerator.framework/Versions/A/IOAccelerator
0x7fff591bf000 -     0x7fff591bffff  com.apple.IOPlatformPluginFamily (1.0 - 1) <858CBC0E-E362-3BC3-9B6A-591F49A36D3F> /System/Library/PrivateFrameworks/IOPlatformPluginFamily.framework/Versions/A/IOPlatformPluginFamily
0x7fff591c0000 -     0x7fff591d9ff7  com.apple.IOPresentment (1.0 - 37) <751130A1-8639-3BDA-BF8F-A3BE54427E43> /System/Library/PrivateFrameworks/IOPresentment.framework/Versions/A/IOPresentment
0x7fff595ec000 -     0x7fff5961bff7  com.apple.IconServices (379 - 379) <BE9E71B4-C00E-317D-9093-6E637C905A09> /System/Library/PrivateFrameworks/IconServices.framework/Versions/A/IconServices
0x7fff59746000 -     0x7fff5974afff  com.apple.InternationalSupport (1.0 - 10.15.6) <F0E300AD-1E67-3D57-B179-C2212F7CD00C> /System/Library/PrivateFrameworks/InternationalSupport.framework/Versions/A/InternationalSupport
0x7fff597b7000 -     0x7fff597c4fff  com.apple.IntlPreferences (2.0 - 227.15.8) <41EA1B38-1F8B-3C58-A51B-37FA2346E8DC> /System/Library/PrivateFrameworks/IntlPreferences.framework/Versions/A/IntlPreferences
0x7fff598ba000 -     0x7fff598cdfff  com.apple.security.KeychainCircle.KeychainCircle (1.0 - 1) <10A17A9D-564E-3841-A433-D6D7401ED733> /System/Library/PrivateFrameworks/KeychainCircle.framework/Versions/A/KeychainCircle
0x7fff598e8000 -     0x7fff599dffff  com.apple.LanguageModeling (1.0 - 159.15.15) <E524CC46-42C7-3046-AD6C-5D5D768EA478> /System/Library/PrivateFrameworks/LanguageModeling.framework/Versions/A/LanguageModeling
0x7fff599e0000 -     0x7fff59a21ff7  com.apple.Lexicon-framework (1.0 - 33.15.10) <90C1CFE1-9935-3F4F-8A9B-1DD697F2FF3D> /System/Library/PrivateFrameworks/Lexicon.framework/Versions/A/Lexicon
0x7fff59a28000 -     0x7fff59a2eff7  com.apple.LinguisticData (1.0 - 238.15.29) <D27B30BA-3F5D-3AF2-895C-3B64569EEA1B> /System/Library/PrivateFrameworks/LinguisticData.framework/Versions/A/LinguisticData
0x7fff5a28b000 -     0x7fff5a28efff  com.apple.Mangrove (1.0 - 25) <8744DBF9-3375-392C-8EE6-24373E0D19E8> /System/Library/PrivateFrameworks/Mangrove.framework/Versions/A/Mangrove
0x7fff5a31c000 -     0x7fff5a343ffb  com.apple.MarkupUI (1.0 - 232.3.27) <1A5E88CA-36C3-30A8-9D39-71CC6923D009> /System/Library/PrivateFrameworks/MarkupUI.framework/Versions/A/MarkupUI
0x7fff5a3ac000 -     0x7fff5a3dfff3  com.apple.MediaKit (16 - 906) <15D4EDA2-AAAC-3CF3-BB2B-3A92AECC932D> /System/Library/PrivateFrameworks/MediaKit.framework/Versions/A/MediaKit
0x7fff5a3e0000 -     0x7fff5a71eff3  com.apple.MediaRemote (1.0 - 1) <DBA5BA26-8E78-34EC-8110-438DDA819564> /System/Library/PrivateFrameworks/MediaRemote.framework/Versions/A/MediaRemote
0x7fff5a71f000 -     0x7fff5a742ff7  com.apple.MediaServices (1.0 - 1) <E0D045E1-4B8C-321E-8089-6174D1C3584E> /System/Library/PrivateFrameworks/MediaServices.framework/Versions/A/MediaServices
0x7fff5a788000 -     0x7fff5a7b0ffb  com.apple.spotlight.metadata.utilities (1.0 - 1191.51) <7CD28A81-F0D6-3575-8F83-3D45D53F72BB> /System/Library/PrivateFrameworks/MetadataUtilities.framework/Versions/A/MetadataUtilities
0x7fff5a7b1000 -     0x7fff5a843fff  com.apple.gpusw.MetalTools (1.0 - 1) <60BE7793-D8DE-3DF1-94D7-503301EC1E72> /System/Library/PrivateFrameworks/MetalTools.framework/Versions/A/MetalTools
0x7fff5a9ed000 -     0x7fff5aa08fff  com.apple.MobileKeyBag (2.0 - 1.0) <E9F2FF73-22D0-35B5-BD2C-9DD8FDB12BCC> /System/Library/PrivateFrameworks/MobileKeyBag.framework/Versions/A/MobileKeyBag
0x7fff5aa19000 -     0x7fff5aa95ff7  com.apple.Montreal (1.0 - 42.15.8) <F7AAEEC2-B981-30C4-995F-4D98FB808984> /System/Library/PrivateFrameworks/Montreal.framework/Versions/A/Montreal
0x7fff5aa96000 -     0x7fff5aac0ff7  com.apple.MultitouchSupport.framework (2400.15 - 2400.15) <A2BB198C-0B1A-3988-8611-9A9BCCE650B5> /System/Library/PrivateFrameworks/MultitouchSupport.framework/Versions/A/MultitouchSupport
0x7fff5abbb000 -     0x7fff5acb2ff7  com.apple.Navigation (1.0 - 1) <85C6DC0A-7AAD-352F-9B58-5838A0ECD84F> /System/Library/PrivateFrameworks/Navigation.framework/Versions/A/Navigation
0x7fff5ad32000 -     0x7fff5ad3cfff  com.apple.NetAuth (6.2 - 6.2) <55DC741A-A01A-380C-B2D3-244241DA1F2C> /System/Library/PrivateFrameworks/NetAuth.framework/Versions/A/NetAuth
0x7fff5b607000 -     0x7fff5b65dfff  com.apple.OTSVG (1.0 - ???) <A0E0FC0B-B48F-3639-9C50-BAECC72988D5> /System/Library/PrivateFrameworks/OTSVG.framework/Versions/A/OTSVG
0x7fff5c6b9000 -     0x7fff5c7bffff  com.apple.PencilKit (1.0 - 1) <30261DA0-5099-3ECE-8DF6-E2D15BFA2B5C> /System/Library/PrivateFrameworks/PencilKit.framework/Versions/A/PencilKit
0x7fff5c7c0000 -     0x7fff5c7cfff3  com.apple.PerformanceAnalysis (1.217 - 217) <8560F263-31F4-3CCA-84B1-30C296DC1A7D> /System/Library/PrivateFrameworks/PerformanceAnalysis.framework/Versions/A/PerformanceAnalysis
0x7fff5ca2a000 -     0x7fff5ca2afff  com.apple.PhoneNumbers (1.0 - 1) <739CE787-1F32-3EE3-90C7-4D0522A25092> /System/Library/PrivateFrameworks/PhoneNumbers.framework/Versions/A/PhoneNumbers
0x7fff5e730000 -     0x7fff5e787fff  com.apple.ProtectedCloudStorage (1.0 - 1) <737DEC8B-342E-3BB2-AF69-D4428D467E4E> /System/Library/PrivateFrameworks/ProtectedCloudStorage.framework/Versions/A/ProtectedCloudStorage
0x7fff5e788000 -     0x7fff5e7a6ff7  com.apple.ProtocolBuffer (1 - 263) <C5AC21FB-74AD-3FC2-B231-B1376751BBAE> /System/Library/PrivateFrameworks/ProtocolBuffer.framework/Versions/A/ProtocolBuffer
0x7fff5e93a000 -     0x7fff5e93dff3  com.apple.QuickLookNonBaseSystem (1.0 - 1) <941AB8E3-BA18-326D-AA59-BA30FFC4C6AC> /System/Library/PrivateFrameworks/QuickLookNonBaseSystem.framework/Versions/A/QuickLookNonBaseSystem
0x7fff5e93e000 -     0x7fff5e954ff3  com.apple.QuickLookThumbnailing (1.0 - 1) <AAF7A93C-5553-3476-B2F2-B8B1DA2BEF54> /System/Library/PrivateFrameworks/QuickLookThumbnailing.framework/Versions/A/QuickLookThumbnailing
0x7fff5e955000 -     0x7fff5e9adf0f  com.apple.ROCKit (24 - 24) <5437F6F7-453F-3D75-9E87-D2A090D82D25> /System/Library/PrivateFrameworks/ROCKit.framework/Versions/A/ROCKit
0x7fff5ea72000 -     0x7fff5ea7eff3  com.apple.xpc.RemoteServiceDiscovery (1.0 - 1336.201.2) <FB030135-1633-378F-A7A6-B1A81AD068A2> /System/Library/PrivateFrameworks/RemoteServiceDiscovery.framework/Versions/A/RemoteServiceDiscovery
0x7fff5ea91000 -     0x7fff5eab4ffb  com.apple.RemoteViewServices (2.0 - 128) <68530B4D-B2C0-3271-941B-D9EA62095727> /System/Library/PrivateFrameworks/RemoteViewServices.framework/Versions/A/RemoteViewServices
0x7fff5eab5000 -     0x7fff5eac9fff  com.apple.xpc.RemoteXPC (1.0 - 1336.201.2) <1E00A78B-1934-39A0-8F35-48CBEB93D04C> /System/Library/PrivateFrameworks/RemoteXPC.framework/Versions/A/RemoteXPC
0x7fff5f920000 -     0x7fff5f96aff7  com.apple.Safari.SafeBrowsing (606 - 606.1.36.1.9) <5ABFF535-18D9-395C-877F-66013774824D> /System/Library/PrivateFrameworks/SafariSafeBrowsing.framework/Versions/A/SafariSafeBrowsing
0x7fff60422000 -     0x7fff60541fff  com.apple.Sharing (1176.11 - 1176.11) <9881AEAD-5410-33F7-A852-770C7FE677C9> /System/Library/PrivateFrameworks/Sharing.framework/Versions/A/Sharing
0x7fff612f3000 -     0x7fff615a3ff7  com.apple.SkyLight (1.600.0 - 336.80.6) <5F7D2312-0003-354C-82BC-DC346B1A98E6> /System/Library/PrivateFrameworks/SkyLight.framework/Versions/A/SkyLight
0x7fff61d72000 -     0x7fff61d7ffff  com.apple.SpeechRecognitionCore (5.0.21 - 5.0.21) <816EC315-3E76-37B7-A495-B4AE031DA439> /System/Library/PrivateFrameworks/SpeechRecognitionCore.framework/Versions/A/SpeechRecognitionCore
0x7fff62be0000 -     0x7fff62c6dff7  com.apple.Symbolication (10.0 - 64254.5) <7D5FB79E-1121-3DB0-9CBE-C023835ACE60> /System/Library/PrivateFrameworks/Symbolication.framework/Versions/A/Symbolication
0x7fff63176000 -     0x7fff63183ff3  com.apple.TCC (1.0 - 1) <55C045F7-D8AB-3BE6-970B-9457FA78E7E3> /System/Library/PrivateFrameworks/TCC.framework/Versions/A/TCC
0x7fff633f2000 -     0x7fff634b9ff7  com.apple.TextureIO (3.8.4 - 3.8.1) <F9D5F55D-9A33-326E-8B2F-B533CC91DD64> /System/Library/PrivateFrameworks/TextureIO.framework/Versions/A/TextureIO
0x7fff63517000 -     0x7fff63532fff  com.apple.ToneKit (1.0 - 1) <B353747A-3E09-3FA3-BDB2-598A891ACA8A> /System/Library/PrivateFrameworks/ToneKit.framework/Versions/A/ToneKit
0x7fff63533000 -     0x7fff6355bffb  com.apple.ToneLibrary (1.0 - 1) <3AEA8490-6454-3156-B11D-6B816EA2FE9A> /System/Library/PrivateFrameworks/ToneLibrary.framework/Versions/A/ToneLibrary
0x7fff6357a000 -     0x7fff63734fff  com.apple.UIFoundation (1.0 - 550.35) <1CAAA3AC-1477-3E24-B55C-07A704D7CA03> /System/Library/PrivateFrameworks/UIFoundation.framework/Versions/A/UIFoundation
0x7fff63783000 -     0x7fff63789fff  com.apple.URLFormatting (59 - 59.34) <D104A904-5B18-368E-8290-35212094D9F5> /System/Library/PrivateFrameworks/URLFormatting.framework/Versions/A/URLFormatting
0x7fff6394d000 -     0x7fff6403eff7  com.apple.VectorKit (1.0 - 1360.20.2.5.56) <6DEFF0B3-3EB7-31DD-B404-611E9368CB50> /System/Library/PrivateFrameworks/VectorKit.framework/Versions/A/VectorKit
0x7fff64422000 -     0x7fff6450bfff  com.apple.ViewBridge (400.1 - 400.1) <0BCCA232-710B-3F84-8341-A30F77B3A4E9> /System/Library/PrivateFrameworks/ViewBridge.framework/Versions/A/ViewBridge
0x7fff6498b000 -     0x7fff64bf7ffb  libAWDSupportFramework.dylib (865) <054B6F72-B75B-3AFC-9E9C-9929C9634200> /System/Library/PrivateFrameworks/WirelessDiagnostics.framework/Versions/A/Libraries/libAWDSupportFramework.dylib
0x7fff64bf8000 -     0x7fff64c09fff  libprotobuf-lite.dylib (865) <B69A744C-4920-3587-A987-A0D349437F4B> /System/Library/PrivateFrameworks/WirelessDiagnostics.framework/Versions/A/Libraries/libprotobuf-lite.dylib
0x7fff64c0a000 -     0x7fff64c6cff7  libprotobuf.dylib (865) <7867D62B-1FDC-3F06-B234-4B6CE5D10602> /System/Library/PrivateFrameworks/WirelessDiagnostics.framework/Versions/A/Libraries/libprotobuf.dylib
0x7fff64c6d000 -     0x7fff64cb3fff  com.apple.awd (1.0 - 930.11) <534B230C-8453-3F01-B6B8-4C1226D3F1E8> /System/Library/PrivateFrameworks/WirelessDiagnostics.framework/Versions/A/WirelessDiagnostics
0x7fff64d26000 -     0x7fff64d29fff  com.apple.dt.XCTTargetBootstrap (1.0 - 1) <63A533F6-988D-3FED-A1C7-20BC725A0D4B> /System/Library/PrivateFrameworks/XCTTargetBootstrap.framework/Versions/A/XCTTargetBootstrap
0x7fff6515a000 -     0x7fff6515cff3  com.apple.loginsupport (1.0 - 1) <5F1E000D-0674-3413-AB3E-83F7974666FB> /System/Library/PrivateFrameworks/login.framework/Versions/A/Frameworks/loginsupport.framework/Versions/A/loginsupport
0x7fff6515d000 -     0x7fff65172fff  com.apple.login (3.0 - 3.0) <474C5E41-1326-3E78-A154-218D618D6BD4> /System/Library/PrivateFrameworks/login.framework/Versions/A/login
0x7fff651a9000 -     0x7fff651dbffb  com.apple.contacts.vCard (1.0 - ???) <18815F93-065A-3A4D-BEFB-243C1A5D9F91> /System/Library/PrivateFrameworks/vCard.framework/Versions/A/vCard
0x7fff65382000 -     0x7fff65395ffb  libAccessibility.dylib (2402.6.10.3) <3044BCB8-1470-3054-9FB6-3D88AA57115B> /usr/lib/libAccessibility.dylib
0x7fff65416000 -     0x7fff6544efff  libCRFSuite.dylib (41.15.4) <62EDD39F-6D1B-334B-A9A2-5800714255BB> /usr/lib/libCRFSuite.dylib
0x7fff65451000 -     0x7fff6545cff7  libChineseTokenizer.dylib (28.15.3) <8CD1C213-7F62-3F02-BFB1-D0A5EFF92AB0> /usr/lib/libChineseTokenizer.dylib
0x7fff6545d000 -     0x7fff654e9ff7  libCoreStorage.dylib (546.50.1) <F56AD958-416C-38EA-9829-DEAAB1F0C155> /usr/lib/libCoreStorage.dylib
0x7fff654ed000 -     0x7fff654eeff7  libDiagnosticMessagesClient.dylib (107) <C542CB3C-AA44-3D7F-B88C-79CC31B481AB> /usr/lib/libDiagnosticMessagesClient.dylib
0x7fff65525000 -     0x7fff656e8ff7  libFosl_dynamic.dylib (18.3.2) <6EF1CB2A-2BDA-3458-B631-F794D72660FD> /usr/lib/libFosl_dynamic.dylib
0x7fff6573e000 -     0x7fff6575dffb  libMobileGestalt.dylib (645.200.76) <A2C32318-0E35-3963-B9B7-E1E92AD33BA6> /usr/lib/libMobileGestalt.dylib
0x7fff6575e000 -     0x7fff6575efff  libOpenScriptingUtil.dylib (178) <2EEBF84D-9E00-3570-AC0C-C49C8D25A8BF> /usr/lib/libOpenScriptingUtil.dylib
0x7fff6589f000 -     0x7fff658a0ffb  libSystem.B.dylib (1252.200.5) <D5133811-9D66-3DEB-9521-0A67347C9A54> /usr/lib/libSystem.B.dylib
0x7fff658a1000 -     0x7fff65929ff7  libTelephonyUtilDynamic.dylib (3608) <05694AE8-9065-36CD-A03B-15D23D09414E> /usr/lib/libTelephonyUtilDynamic.dylib
0x7fff6592a000 -     0x7fff6592bfff  libThaiTokenizer.dylib (2.15.1) <A8235B04-F541-3856-BE2E-B58EE0483AD9> /usr/lib/libThaiTokenizer.dylib
0x7fff6593e000 -     0x7fff65954ffb  libapple_nghttp2.dylib (1.24.1) <B8D45114-3868-3154-BC35-22597E3E7D8A> /usr/lib/libapple_nghttp2.dylib
0x7fff65955000 -     0x7fff6597effb  libarchive.2.dylib (54.200.3) <B47C54A0-3A30-374A-BD99-2304B9B0EC82> /usr/lib/libarchive.2.dylib
0x7fff6597f000 -     0x7fff659fefef  libate.dylib (1.13.8) <C647A80F-6F80-3FDA-A9B4-92800999F963> /usr/lib/libate.dylib
0x7fff65a02000 -     0x7fff65a02ff3  libauto.dylib (187) <01824E49-F2EF-3FC1-ABF3-782EFDF6CA17> /usr/lib/libauto.dylib
0x7fff65ada000 -     0x7fff65aeaff3  libbsm.0.dylib (39.200.18) <5E5098D0-F7B2-32A1-8038-E709F6718D4E> /usr/lib/libbsm.0.dylib
0x7fff65aeb000 -     0x7fff65af9fff  libbz2.1.0.dylib (38.200.3) <4EE3C5E8-BEF3-3910-A231-B1AE2B437E01> /usr/lib/libbz2.1.0.dylib
0x7fff65afa000 -     0x7fff65b51ff7  libc++.1.dylib (400.9.4) <D4AB366F-48A9-3C7D-91BD-41198F69DD57> /usr/lib/libc++.1.dylib
0x7fff65b52000 -     0x7fff65b67fff  libc++abi.dylib (400.17) <BA948A32-9024-3E55-98D4-18E31F6AED25> /usr/lib/libc++abi.dylib
0x7fff65b68000 -     0x7fff65b68ff3  libcharset.1.dylib (51.200.6) <D998A58B-E4A8-3685-9A6A-43AFC28100EB> /usr/lib/libcharset.1.dylib
0x7fff65b69000 -     0x7fff65b79ffb  libcmph.dylib (6.15.1) <5D776FF6-DF7F-3EDD-B920-C07ED76C672B> /usr/lib/libcmph.dylib
0x7fff65b7a000 -     0x7fff65b92ffb  libcompression.dylib (52.200.13) <EA767836-CBDC-318D-AC14-963C90D6CC67> /usr/lib/libcompression.dylib
0x7fff65e3d000 -     0x7fff65e53fff  libcoretls.dylib (155.200.6) <6E68F922-752C-311F-B56D-EE391E6AE1F7> /usr/lib/libcoretls.dylib
0x7fff65e54000 -     0x7fff65e55ff3  libcoretls_cfhelpers.dylib (155.200.6) <7300BA76-39D2-349E-9FB8-EBE5947A708A> /usr/lib/libcoretls_cfhelpers.dylib
0x7fff664b8000 -     0x7fff664c3ff7  libcsfde.dylib (546.50.1) <65E8F1F1-665A-381E-8932-D7CBA451991B> /usr/lib/libcsfde.dylib
0x7fff664cc000 -     0x7fff66522ffb  libcups.2.dylib (462.9) <51E06E95-891F-3B88-A8C3-35B514C57239> /usr/lib/libcups.2.dylib
0x7fff6665a000 -     0x7fff6665afff  libenergytrace.dylib (17.200.1) <D62ED169-B91C-3CCB-ADF5-E66AE4007B51> /usr/lib/libenergytrace.dylib
0x7fff6668c000 -     0x7fff66691ff7  libgermantok.dylib (17.15.2) <9CBF0658-E83B-32E6-B674-3EE72D22C041> /usr/lib/libgermantok.dylib
0x7fff66692000 -     0x7fff66697ff7  libheimdal-asn1.dylib (520.200.17) <58971629-3850-3905-A9A1-09FCF7A32815> /usr/lib/libheimdal-asn1.dylib
0x7fff666c3000 -     0x7fff667b4ff7  libiconv.2.dylib (51.200.6) <3240A278-F537-3EC8-BE0C-983797520A50> /usr/lib/libiconv.2.dylib
0x7fff667b5000 -     0x7fff66a18ffb  libicucore.A.dylib (62107.0.1) <EAE6FC43-3AD2-3A53-9F7A-4E5E5F66D006> /usr/lib/libicucore.A.dylib
0x7fff66a65000 -     0x7fff66a66fff  liblangid.dylib (128.15.1) <F79B6250-C0B1-3E8E-851F-6CA33B4311A3> /usr/lib/liblangid.dylib
0x7fff66a67000 -     0x7fff66a7ffff  liblzma.5.dylib (10.200.3) <3ADDFA63-F37A-3C9C-91E4-58EE3113B9A1> /usr/lib/liblzma.5.dylib
0x7fff66a97000 -     0x7fff66b47fff  libmecab.1.0.0.dylib (779.15.23) <6A38FCDA-17CE-30C3-AB66-A714CF645384> /usr/lib/libmecab.1.0.0.dylib
0x7fff66b48000 -     0x7fff66d85fff  libmecabra.dylib (779.15.23) <30E102AA-F3D3-3572-A1AE-1F2287DEF696> /usr/lib/libmecabra.dylib
0x7fff66f5d000 -     0x7fff672b5fff  libnetwork.dylib (1229.200.109) <AD59D28C-CCB2-3B34-B904-8CCCEB2CF320> /usr/lib/libnetwork.dylib
0x7fff67346000 -     0x7fff67accfe7  libobjc.A.dylib (750) <2E868147-8818-359E-8CD7-A8B80665928F> /usr/lib/libobjc.A.dylib
0x7fff67adf000 -     0x7fff67ae3ffb  libpam.2.dylib (22.200.1) <8C419238-675A-3C41-B8D4-95E391CA630F> /usr/lib/libpam.2.dylib
0x7fff67ae6000 -     0x7fff67b1cff7  libpcap.A.dylib (79.200.4) <5939AB23-B2A9-3C03-B6C1-4F0E5A21D9FC> /usr/lib/libpcap.A.dylib
0x7fff67c36000 -     0x7fff67c4effb  libresolv.9.dylib (65.200.2) <0FEAEB01-B926-37FA-AB47-99BAC481C10B> /usr/lib/libresolv.9.dylib
0x7fff67c8d000 -     0x7fff67c9fff7  libsasl2.2.dylib (211) <205CC13E-4ED7-3CE9-987F-12B28C6115A7> /usr/lib/libsasl2.2.dylib
0x7fff67ca0000 -     0x7fff67ca1ffb  libspindump.dylib (266) <0E60D709-0A48-3905-ACD1-9DDE6FD8B476> /usr/lib/libspindump.dylib
0x7fff67ca2000 -     0x7fff67e79fe7  libsqlite3.dylib (274.20) <4434B695-BC65-30D6-AFED-1B6488DB3D2E> /usr/lib/libsqlite3.dylib
0x7fff68106000 -     0x7fff68109ffb  libutil.dylib (51.200.4) <91EE9BF4-FB06-3260-B502-7EFDAD5AF59B> /usr/lib/libutil.dylib
0x7fff6810a000 -     0x7fff68117fff  libxar.1.dylib (404) <4B4D0206-0B62-3E89-AD07-E7BB9E4DFA68> /usr/lib/libxar.1.dylib
0x7fff6811c000 -     0x7fff681fffff  libxml2.2.dylib (32.6) <BFF70F01-6755-36B9-B7AA-724743E63503> /usr/lib/libxml2.2.dylib
0x7fff68200000 -     0x7fff68228ff3  libxslt.1.dylib (16.1) <F191E8B9-7530-30CA-873B-2FA2BF2D6374> /usr/lib/libxslt.1.dylib
0x7fff68229000 -     0x7fff6823bffb  libz.1.dylib (70.200.4) <99A3D725-8388-38B4-B66C-5E9006E6F072> /usr/lib/libz.1.dylib
0x7fff682ac000 -     0x7fff682b0ff3  libcache.dylib (81) <FE21A7E9-DBEB-33AC-836B-785AD036ACF4> /usr/lib/system/libcache.dylib
0x7fff682b1000 -     0x7fff682bbff3  libcommonCrypto.dylib (60118.200.6) <78093D4F-91DB-35C8-981A-13375778B2E7> /usr/lib/system/libcommonCrypto.dylib
0x7fff682bc000 -     0x7fff682c3fff  libcompiler_rt.dylib (63.4) <A4D9CF37-D076-3CE9-95F1-DA89DA1601B6> /usr/lib/system/libcompiler_rt.dylib
0x7fff682c4000 -     0x7fff682cdff3  libcopyfile.dylib (146.200.3) <4BCDADBF-79F5-3829-B47D-64DA0D44BCBF> /usr/lib/system/libcopyfile.dylib
0x7fff682ce000 -     0x7fff68352fff  libcorecrypto.dylib (602.200.50) <7AEC5B72-0B92-37E8-808B-6732DB714139> /usr/lib/system/libcorecrypto.dylib
0x7fff68413000 -     0x7fff68442fff  libdyld.dylib (625.13) <4B16C209-83D4-3817-9B62-C2F7FFB23755> /usr/lib/system/libdyld.dylib
0x7fff68443000 -     0x7fff68443ffb  libkeymgr.dylib (30) <A73AA788-C35C-3284-BFCA-95B1BBDF0CF3> /usr/lib/system/libkeymgr.dylib
0x7fff68444000 -     0x7fff68450ff7  libkxld.dylib (4903.201.2) <EAF1CF8D-3843-33BE-8126-30994685B8F0> /usr/lib/system/libkxld.dylib
0x7fff68451000 -     0x7fff68451ff7  liblaunch.dylib (1336.201.2) <43E6698E-155E-3EAE-BAFF-CA5FCB35325C> /usr/lib/system/liblaunch.dylib
0x7fff68452000 -     0x7fff68457fff  libmacho.dylib (917) <17BF7038-9C70-3EE1-9E96-3AE10D49669E> /usr/lib/system/libmacho.dylib
0x7fff68458000 -     0x7fff6845aff3  libquarantine.dylib (86.200.11) <C70DA995-0D6E-302C-A15E-F7F03A3857B4> /usr/lib/system/libquarantine.dylib
0x7fff6845b000 -     0x7fff6845cff3  libremovefile.dylib (45.200.2) <D74A307B-3DC7-3992-B16C-DACB8207BE13> /usr/lib/system/libremovefile.dylib
0x7fff6845d000 -     0x7fff68474ff3  libsystem_asl.dylib (356.200.4) <EC9D8AD4-E5CB-3765-804A-9E1E9DC045D2> /usr/lib/system/libsystem_asl.dylib
0x7fff68475000 -     0x7fff68475fff  libsystem_blocks.dylib (73) <26419398-C30C-30F1-B656-A92AFA9560F6> /usr/lib/system/libsystem_blocks.dylib
0x7fff68476000 -     0x7fff684fefff  libsystem_c.dylib (1272.200.26) <3DEEE96E-6DF6-35AD-8654-D69AC26B907B> /usr/lib/system/libsystem_c.dylib
0x7fff684ff000 -     0x7fff68502ff7  libsystem_configuration.dylib (963.200.27) <02CC3996-B34E-333C-8806-AE2699D34424> /usr/lib/system/libsystem_configuration.dylib
0x7fff68503000 -     0x7fff68506ff7  libsystem_coreservices.dylib (66) <254B6849-2C8F-302C-8616-B8324A11AB30> /usr/lib/system/libsystem_coreservices.dylib
0x7fff68507000 -     0x7fff6850dffb  libsystem_darwin.dylib (1272.200.26) <974E9EF7-DE72-34B7-B056-0A81C10DF8EB> /usr/lib/system/libsystem_darwin.dylib
0x7fff6850e000 -     0x7fff68514ff7  libsystem_dnssd.dylib (878.200.35) <FFC665AA-B257-35AD-BD8B-32FD42C2EEC1> /usr/lib/system/libsystem_dnssd.dylib
0x7fff68515000 -     0x7fff68561ff3  libsystem_info.dylib (517.200.9) <0707C387-D7DE-372E-8FF1-3DE5C91932D6> /usr/lib/system/libsystem_info.dylib
0x7fff68562000 -     0x7fff68589ff7  libsystem_kernel.dylib (4903.201.2) <45FAA4C0-D553-34FD-ADF8-884886AE0D2A> /usr/lib/system/libsystem_kernel.dylib
0x7fff6858a000 -     0x7fff685d5ff7  libsystem_m.dylib (3158.200.7) <43D1796B-954F-37D6-B1AC-9D80DF0655A2> /usr/lib/system/libsystem_m.dylib
0x7fff685d6000 -     0x7fff685faff7  libsystem_malloc.dylib (166.200.60) <846F6898-117C-3427-A8FB-3772FFC2410B> /usr/lib/system/libsystem_malloc.dylib
0x7fff685fb000 -     0x7fff68606ffb  libsystem_networkextension.dylib (767.200.40) <F84D5474-4DC1-3E1A-AE00-8CE9593278B4> /usr/lib/system/libsystem_networkextension.dylib
0x7fff68607000 -     0x7fff6860efff  libsystem_notify.dylib (172.200.21) <BCCB222F-DC64-3954-A836-DCCE6659CA5A> /usr/lib/system/libsystem_notify.dylib
0x7fff6860f000 -     0x7fff68618fef  libsystem_platform.dylib (177.200.16) <B75B04AD-69FE-3ADE-84D2-C17972FC8F49> /usr/lib/system/libsystem_platform.dylib
0x7fff68624000 -     0x7fff68627ff7  libsystem_sandbox.dylib (851.201.1) <FBA7E09B-F10F-3424-90EA-B4999B7FB461> /usr/lib/system/libsystem_sandbox.dylib
0x7fff68628000 -     0x7fff6862aff7  libsystem_secinit.dylib (30.200.13) <CBEAB62B-F0A0-342F-9878-CADC14A3CB0D> /usr/lib/system/libsystem_secinit.dylib
0x7fff6862b000 -     0x7fff68632ff7  libsystem_symptoms.dylib (820.207.88) <B6E22FA8-0F7B-36FD-9D99-284056D3CB47> /usr/lib/system/libsystem_symptoms.dylib
0x7fff68633000 -     0x7fff68648ff7  libsystem_trace.dylib (906.200.86) <7983ED77-18B5-39A5-BE19-AE4F2832ADEA> /usr/lib/system/libsystem_trace.dylib
0x7fff6864a000 -     0x7fff6864fffb  libunwind.dylib (35.4) <41222EF6-2233-3CF4-947A-15D48CB8C030> /usr/lib/system/libunwind.dylib
0x7fff68650000 -     0x7fff68680fff  libxpc.dylib (1336.201.2) <0A8747D1-33AA-37E1-B97A-BA9B95FE4E8C> /usr/lib/system/libxpc.dylib
Sample analysis of process 72841 written to file /dev/stdout
