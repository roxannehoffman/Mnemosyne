# Note:fix sample location

# syd hot dog
sampleLen01 = sample_duration "/Users/roxannehoffman/sounds/sydhotdog.wav"
print "sample01 length: #{sampleLen01}"
sample "/Users/roxannehoffman/sounds/sydhotdog.wav", amp: 0.8, attack: (0.20*sampleLen01), sustain: (0.30*sampleLen01), release: (0.50*sampleLen01)

# shanghai
sleep 0.25*sampleLen01
sampleLen03 = sample_duration "/Users/roxannehoffman/sounds/shanghai.wav"
print "sample03 length: #{sampleLen03}"
sample "/Users/roxannehoffman/sounds/shanghai.wav", amp: 0.5, attack: (0.20*sampleLen03), sustain: (0.30*sampleLen03), release: (0.50*sampleLen03)

# loomis drag
sleep 1.1*sampleLen03
sampleLen02 = sample_duration "/Users/roxannehoffman/sounds/loomisdrag.wav"
print "sample02 length: #{sampleLen02}"
sample "/Users/roxannehoffman/sounds/loomisdrag.wav", amp: 0.3, finish: 0.8, attack: (0.10*sampleLen02), attack_level: 1, decay: 0.5, sustain_level: 0.5, sustain: (0.05*sampleLen02), release: (0.85*sampleLen02)

# fennesz
sleep 0.4*sampleLen02
sampleLen04 = sample_duration "/Users/roxannehoffman/sounds/fennesz.wav"
print "sample04 length: #{sampleLen04}"
sample "/Users/roxannehoffman/sounds/fennesz.wav", amp: 0.6, rate: 0.8, attack: (0.20*sampleLen04), sustain: (0.30*sampleLen04), release: (0.50*sampleLen04)

# Long beach waves
sleep 0.9*sampleLen04
sampleLen05 = sample_duration "/Users/roxannehoffman/sounds/LBWaves.wav"
print "sample05 length: #{sampleLen05}"
sample "/Users/roxannehoffman/sounds/LBWaves.wav", amp: 0.3, rate: 0.8, attack: (0.20*sampleLen05), sustain: (0.30*sampleLen05), release: (0.50*sampleLen05)
sleep 4
sample "/Users/roxannehoffman/sounds/LBWaves.wav", amp: 0.3, rate: 0.6, attack: (0.20*sampleLen05), sustain: (0.30*sampleLen05), release: (0.50*sampleLen05)

# modular synth
sleep sampleLen05
sampleLen06 = sample_duration "/Users/roxannehoffman/sounds/modularsynth.wav"
print "sample06 length: #{sampleLen06}"
sample "/Users/roxannehoffman/sounds/modularsynth.wav", amp: 0.4, attack: (0.20*sampleLen06), sustain: (0.60*sampleLen06), release: (0.20*sampleLen06)

# china airline
sleep 0.75*sampleLen06
sampleLen07 = sample_duration "/Users/roxannehoffman/sounds/chinaairline.wav"
print "sample07 length: #{sampleLen07}"
sample "/Users/roxannehoffman/sounds/chinaairline.wav", amp: 1, attack: (0.20*sampleLen07), sustain: (0.30*sampleLen07), release: (0.50*sampleLen07)

# syd ken
sleep 0.9*sampleLen07
sampleLen08 = sample_duration "/Users/roxannehoffman/sounds/sydken.wav"
print "sample08 length: #{sampleLen08}"
sample "/Users/roxannehoffman/sounds/sydken.wav", amp: 0.75, attack: (0.20*sampleLen08), sustain: (0.30*sampleLen08), release: (0.50*sampleLen08)

# waiting in car
sleep 0.25*sampleLen08
sampleLen09 = sample_duration "/Users/roxannehoffman/sounds/waitingincar.wav"
print "sample09 length: #{sampleLen09}"
sample "/Users/roxannehoffman/sounds/waitingincar.wav", amp: 0.5, finish: 0.6, attack: (0.20*sampleLen09), sustain: (0.30*sampleLen09), release: (0.50*sampleLen09)

# mt eerie
sleep 0.4*sampleLen09
sampleLen10 = sample_duration "/Users/roxannehoffman/sounds/mteerie.wav"
print "sample10 length: #{sampleLen10}"
sample "/Users/roxannehoffman/sounds/mteerie.wav", amp: 1, attack: (0.20*sampleLen10), sustain: (0.30*sampleLen10), release: (0.50*sampleLen10)

# windchime
sleep 0.75*sampleLen10
sampleLen11 = sample_duration "/Users/roxannehoffman/sounds/handmadewindchime.wav"
print "sample11 length: #{sampleLen11}"
sample "/Users/roxannehoffman/sounds/handmadewindchime.wav", amp: 0.6, attack: (0.20*sampleLen11), sustain: (0.30*sampleLen11), release: (0.50*sampleLen11)

# alex swings
sleep 0.75*sampleLen11
sampleLen12 = sample_duration "/Users/roxannehoffman/sounds/alexswings.wav"
print "sample12 length: #{sampleLen12}"
sample "/Users/roxannehoffman/sounds/alexswings.wav", amp: 0.7, attack: (0.20*sampleLen12), sustain: (0.30*sampleLen12), release: (0.50*sampleLen12)

# walking in college
sleep 0.25*sampleLen12
sampleLen13 = sample_duration "/Users/roxannehoffman/sounds/walkingcollege.wav"
print "sample13 length: #{sampleLen13}"
sample "/Users/roxannehoffman/sounds/walkingcollege.wav", amp: 0.6, attack: (0.20*sampleLen13), sustain: (0.30*sampleLen13), release: (0.50*sampleLen13)

# Ana Roxanne
sleep 0.5*sampleLen13
sampleLen14 = sample_duration "/Users/roxannehoffman/sounds/anaroxanne.wav"
print "sample14 length: #{sampleLen14}"
sample "/Users/roxannehoffman/sounds/anaroxanne.wav", amp: 0.6, attack: (0.30*sampleLen14), sustain: (0.20*sampleLen14), release: (0.50*sampleLen14)

# thumb guitar
sleep 0.75*sampleLen14
sampleLen15 = sample_duration "/Users/roxannehoffman/sounds/thumbguitar.wav"
print "sample15 length: #{sampleLen15}"
sample "/Users/roxannehoffman/sounds/thumbguitar.wav", amp: 0.7, attack: (0.20*sampleLen15), sustain: (0.50*sampleLen15), release: (0.30*sampleLen15)

# laugh ID
sleep 0.25*sampleLen15
sampleLen16 = sample_duration "/Users/roxannehoffman/sounds/laugh-ID.wav"
print "sample16 length: #{sampleLen16}"
sample "/Users/roxannehoffman/sounds/laugh-ID.wav", amp: 0.5, attack: (0.20*sampleLen16), sustain: (0.30*sampleLen16), release: (0.50*sampleLen16)

