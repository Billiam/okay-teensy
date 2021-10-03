#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=100,0
AudioSynthWaveform       waveform2;      //xy=100,50
AudioSynthWaveform       waveform3;      //xy=100,100
AudioSynthWaveform       waveform4;      //xy=100,150
AudioSynthWaveform       waveform5;      //xy=100,200
AudioSynthWaveform       waveform6;      //xy=100,250
AudioSynthWaveform       waveform7;      //xy=100,300
AudioSynthWaveform       waveform8;      //xy=100,350
AudioSynthWaveform       waveform9;      //xy=100,400
AudioSynthWaveform       waveform10;      //xy=100,450
AudioSynthWaveform       waveform11;      //xy=100,500
AudioSynthWaveform       waveform12;      //xy=100,550
AudioSynthWaveform       waveform13;      //xy=100,600
AudioSynthWaveform       waveform14;      //xy=100,650
AudioSynthWaveform       waveform15;      //xy=100,700
AudioSynthWaveform       waveform16;      //xy=100,750
AudioSynthWaveform       waveform17;      //xy=100,800
AudioSynthWaveform       waveform18;      //xy=100,850
AudioSynthWaveform       waveform19;      //xy=100,900
AudioSynthWaveform       waveform20;      //xy=100,950
AudioSynthWaveform       waveform21;      //xy=100,1000
AudioSynthWaveform       waveform22;      //xy=100,1050
AudioSynthWaveform       waveform23;      //xy=100,1100
AudioSynthWaveform       waveform24;      //xy=100,1150

AudioEffectEnvelope       envelope1;      //xy=250,0
AudioEffectEnvelope       envelope2;      //xy=250,50
AudioEffectEnvelope       envelope3;      //xy=250,100
AudioEffectEnvelope       envelope4;      //xy=250,150
AudioEffectEnvelope       envelope5;      //xy=250,200
AudioEffectEnvelope       envelope6;      //xy=250,250
AudioEffectEnvelope       envelope7;      //xy=250,300
AudioEffectEnvelope       envelope8;      //xy=250,350
AudioEffectEnvelope       envelope9;      //xy=250,400
AudioEffectEnvelope       envelope10;      //xy=250,450
AudioEffectEnvelope       envelope11;      //xy=250,500
AudioEffectEnvelope       envelope12;      //xy=250,550
AudioEffectEnvelope       envelope13;      //xy=250,600
AudioEffectEnvelope       envelope14;      //xy=250,650
AudioEffectEnvelope       envelope15;      //xy=250,700
AudioEffectEnvelope       envelope16;      //xy=250,750
AudioEffectEnvelope       envelope17;      //xy=250,800
AudioEffectEnvelope       envelope18;      //xy=250,850
AudioEffectEnvelope       envelope19;      //xy=250,900
AudioEffectEnvelope       envelope20;      //xy=250,950
AudioEffectEnvelope       envelope21;      //xy=250,1000
AudioEffectEnvelope       envelope22;      //xy=250,1050
AudioEffectEnvelope       envelope23;      //xy=250,1100
AudioEffectEnvelope       envelope24;      //xy=250,1150

AudioSynthWavetable       wavetable1;     //xy=100,1200
AudioSynthWavetable       wavetable2;     //xy=100,1250
AudioSynthWavetable       wavetable3;     //xy=100,1300
AudioSynthWavetable       wavetable4;     //xy=100,1350
AudioSynthWavetable       wavetable5;     //xy=100,1400
AudioSynthWavetable       wavetable6;     //xy=100,1450
AudioSynthWavetable       wavetable7;     //xy=100,1500
AudioSynthWavetable       wavetable8;     //xy=100,1550
AudioSynthWavetable       wavetable9;     //xy=100,1600
AudioSynthWavetable       wavetable10;     //xy=100,1650
AudioSynthWavetable       wavetable11;     //xy=100,1700
AudioSynthWavetable       wavetable12;     //xy=100,1750
AudioSynthWavetable       wavetable13;     //xy=100,1800
AudioSynthWavetable       wavetable14;     //xy=100,1850
AudioSynthWavetable       wavetable15;     //xy=100,1900
AudioSynthWavetable       wavetable16;     //xy=100,1950
AudioSynthWavetable       wavetable17;     //xy=100,2000
AudioSynthWavetable       wavetable18;     //xy=100,2050
AudioSynthWavetable       wavetable19;     //xy=100,2100
AudioSynthWavetable       wavetable20;     //xy=100,2150
AudioSynthWavetable       wavetable21;     //xy=100,2200
AudioSynthWavetable       wavetable22;     //xy=100,2250
AudioSynthWavetable       wavetable23;     //xy=100,2300
AudioSynthWavetable       wavetable24;     //xy=100,2350

AudioMixer4              mixer1;         //xy=450,75
AudioMixer4              mixer2;         //xy=450,275
AudioMixer4              mixer3;         //xy=450,475
AudioMixer4              mixer4;         //xy=450,675
AudioMixer4              mixer5;         //xy=450,875
AudioMixer4              mixer6;         //xy=450,1075
AudioMixer4              mixer7;         //xy=450,1275
AudioMixer4              mixer8;         //xy=450,1475
AudioMixer4              mixer9;         //xy=450,1675
AudioMixer4              mixer10;         //xy=450,1875
AudioMixer4              mixer11;         //xy=450,2075
AudioMixer4              mixer12;         //xy=450,2275

AudioMixer4              mixer13;         //xy=650,375
AudioMixer4              mixer14;         //xy=650,1175
AudioMixer4              mixer15;         //xy=650,1975

AudioMixer4              mixer16;         //xy=850,1175

AudioConnection          patchCord1(waveform1, envelope1);
AudioConnection          patchCord2(waveform2, envelope2);
AudioConnection          patchCord3(waveform3, envelope3);
AudioConnection          patchCord4(waveform4, envelope4);
AudioConnection          patchCord5(waveform5, envelope5);
AudioConnection          patchCord6(waveform6, envelope6);
AudioConnection          patchCord7(waveform7, envelope7);
AudioConnection          patchCord8(waveform8, envelope8);
AudioConnection          patchCord9(waveform9, envelope9);
AudioConnection          patchCord10(waveform10, envelope10);
AudioConnection          patchCord11(waveform11, envelope11);
AudioConnection          patchCord12(waveform12, envelope12);
AudioConnection          patchCord13(waveform13, envelope13);
AudioConnection          patchCord14(waveform14, envelope14);
AudioConnection          patchCord15(waveform15, envelope15);
AudioConnection          patchCord16(waveform16, envelope16);
AudioConnection          patchCord17(waveform17, envelope17);
AudioConnection          patchCord18(waveform18, envelope18);
AudioConnection          patchCord19(waveform19, envelope19);
AudioConnection          patchCord20(waveform20, envelope20);
AudioConnection          patchCord21(waveform21, envelope21);
AudioConnection          patchCord22(waveform22, envelope22);
AudioConnection          patchCord23(waveform23, envelope23);
AudioConnection          patchCord24(waveform24, envelope24);
AudioConnection          patchCord25(envelope1, 0, mixer1, 0);
AudioConnection          patchCord26(envelope2, 0, mixer1, 1);
AudioConnection          patchCord27(envelope3, 0, mixer1, 2);
AudioConnection          patchCord28(envelope4, 0, mixer1, 3);
AudioConnection          patchCord29(envelope5, 0, mixer2, 0);
AudioConnection          patchCord30(envelope6, 0, mixer2, 1);
AudioConnection          patchCord31(envelope7, 0, mixer2, 2);
AudioConnection          patchCord32(envelope8, 0, mixer2, 3);
AudioConnection          patchCord33(envelope9, 0, mixer3, 0);
AudioConnection          patchCord34(envelope10, 0, mixer3, 1);
AudioConnection          patchCord35(envelope11, 0, mixer3, 2);
AudioConnection          patchCord36(envelope12, 0, mixer3, 3);
AudioConnection          patchCord37(envelope13, 0, mixer4, 0);
AudioConnection          patchCord38(envelope14, 0, mixer4, 1);
AudioConnection          patchCord39(envelope15, 0, mixer4, 2);
AudioConnection          patchCord40(envelope16, 0, mixer4, 3);
AudioConnection          patchCord41(envelope17, 0, mixer5, 0);
AudioConnection          patchCord42(envelope18, 0, mixer5, 1);
AudioConnection          patchCord43(envelope19, 0, mixer5, 2);
AudioConnection          patchCord44(envelope20, 0, mixer5, 3);
AudioConnection          patchCord45(envelope21, 0, mixer6, 0);
AudioConnection          patchCord46(envelope22, 0, mixer6, 1);
AudioConnection          patchCord47(envelope23, 0, mixer6, 2);
AudioConnection          patchCord48(envelope24, 0, mixer6, 3);

AudioConnection          patchCord49(wavetable1, 0, mixer7, 0);
AudioConnection          patchCord50(wavetable2, 0, mixer7, 1);
AudioConnection          patchCord51(wavetable3, 0, mixer7, 2);
AudioConnection          patchCord52(wavetable4, 0, mixer7, 3);
AudioConnection          patchCord53(wavetable5, 0, mixer8, 0);
AudioConnection          patchCord54(wavetable6, 0, mixer8, 1);
AudioConnection          patchCord55(wavetable7, 0, mixer8, 2);
AudioConnection          patchCord56(wavetable8, 0, mixer8, 3);
AudioConnection          patchCord57(wavetable9, 0, mixer9, 0);
AudioConnection          patchCord58(wavetable10, 0, mixer9, 1);
AudioConnection          patchCord59(wavetable11, 0, mixer9, 2);
AudioConnection          patchCord60(wavetable12, 0, mixer9, 3);
AudioConnection          patchCord61(wavetable13, 0, mixer10, 0);
AudioConnection          patchCord62(wavetable14, 0, mixer10, 1);
AudioConnection          patchCord63(wavetable15, 0, mixer10, 2);
AudioConnection          patchCord64(wavetable16, 0, mixer10, 3);
AudioConnection          patchCord65(wavetable17, 0, mixer11, 0);
AudioConnection          patchCord66(wavetable18, 0, mixer11, 1);
AudioConnection          patchCord67(wavetable19, 0, mixer11, 2);
AudioConnection          patchCord68(wavetable20, 0, mixer11, 3);
AudioConnection          patchCord69(wavetable21, 0, mixer12, 0);
AudioConnection          patchCord70(wavetable22, 0, mixer12, 1);
AudioConnection          patchCord71(wavetable23, 0, mixer12, 2);
AudioConnection          patchCord72(wavetable24, 0, mixer12, 3);

AudioConnection          patchCord73(mixer1, 0, mixer13, 0);
AudioConnection          patchCord74(mixer2, 0, mixer13, 1);
AudioConnection          patchCord75(mixer3, 0, mixer13, 2);
AudioConnection          patchCord76(mixer4, 0, mixer13, 3);
AudioConnection          patchCord77(mixer5, 0, mixer14, 0);
AudioConnection          patchCord78(mixer6, 0, mixer14, 1);
AudioConnection          patchCord79(mixer7, 0, mixer14, 2);
AudioConnection          patchCord80(mixer8, 0, mixer14, 3);
AudioConnection          patchCord81(mixer9, 0, mixer15, 0);
AudioConnection          patchCord82(mixer10, 0, mixer15, 1);
AudioConnection          patchCord83(mixer11, 0, mixer15, 2);
AudioConnection          patchCord84(mixer12, 0, mixer15, 3);
AudioConnection          patchCord85(mixer13, 0, mixer16, 0);
AudioConnection          patchCord86(mixer14, 0, mixer16, 1);
AudioConnection          patchCord87(mixer15, 0, mixer16, 2);

AudioControlSGTL5000     sgtl5000_1;     //xy=1050,1275
AudioOutputI2S           i2s1;           //xy=1050,1175
AudioConnection          patchCord88(mixer16, 0, i2s1, 0);
AudioConnection          patchCord89(mixer16, 0, i2s1, 1);
// GUItool: end automatically generated code