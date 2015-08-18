SplashImage dream.jpg, b fs18, This is Computer Controlled bot


Space:: SoundPlay, 4.wav
Right:: gosub, ri
Left:: gosub, le
Down:: SoundPlay, 4.wav
Up:: SoundPlay, 3.wav
Esc:: exitApp

le:
{ SoundPlay, 1.wav
 sleep, 1000
 SoundPlay, 4.wav
 }
 return
ri:
{ SoundPlay, 2.wav
 sleep, 1000
 SoundPlay, 4.wav
 }
 return