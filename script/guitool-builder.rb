keys = 25
patch = 0
mixer = 0

l1_mixers = ((keys * 2)/4.0).ceil
l2_mixers = (l1_mixers/4.0).ceil
l3_mixers = (l2_mixers/4.0).ceil

mixer_conn = 0

puts "#include <Audio.h>"
puts "#include <Wire.h>"
puts "#include <SPI.h>"
puts "#include <SD.h>"
puts "#include <SerialFlash.h>"
puts
puts "// GUItool: begin automatically generated code"

keys.times do |i|
  puts "AudioSynthWaveform       waveform#{i + 1};      //xy=100,#{i * 50}"
end

puts
keys.times do |i|
  puts "AudioEffectEnvelope       envelope#{i + 1};      //xy=250,#{i * 50}"
end

puts
keys.times do |i|
  puts "AudioSynthWavetable       wavetable#{i + 1};     //xy=100,#{(i + keys) * 50}"
end

puts
l1_mixers.times do |i|
  puts "AudioMixer4              mixer#{mixer+=1};         //xy=450,#{i * 200 + 75}"
end

puts
l2_mixers.times do |i|
  puts "AudioMixer4              mixer#{mixer+=1};         //xy=650,#{i * 800 + 375}"
end

puts
l3_mixers.times do |i|
  puts "AudioMixer4              mixer#{mixer+=1};         //xy=850,#{keys * 50 - 25}"
end

puts
# Master mixer
puts "AudioMixer4              volume_control;         //xy=1050,#{keys * 50 - 25}"

puts
# Connect waveforms to envelopes
keys.times do |i|
  n = i + 1
  puts "AudioConnection          patchCord#{patch+=1}(waveform#{n}, envelope#{n});"
end

puts
# connect envelopes to l1 mixers
keys.times do |i|
  m = (mixer_conn / 4) + 1
  j = mixer_conn % 4
  mixer_conn += 1

  puts "AudioConnection          patchCord#{patch+=1}(envelope#{i+1}, 0, mixer#{m}, #{j});"
end

puts
# connect wavetables to l1 mixers
keys.times do |i|
  m = (mixer_conn / 4) + 1
  j = mixer_conn % 4
  mixer_conn += 1

  puts "AudioConnection          patchCord#{patch+=1}(wavetable#{i+1}, 0, mixer#{m}, #{j});"
end


puts
# connect l1 mixers tol2 mixers
l1_mixers.times do |i|
  mixer_out = i + 1
  mixer_in = l1_mixers + i/4 + 1
  j = i % 4

  puts "AudioConnection          patchCord#{patch+=1}(mixer#{mixer_out}, 0, mixer#{mixer_in}, #{j});"
end

puts
# connect l2 mixers to l3 mixers
l2_mixers.times do |i|
  mixer_out = l1_mixers + i + 1
  mixer_in = l1_mixers + l2_mixers + i/4 + 1
  j = i % 4

  puts "AudioConnection          patchCord#{patch+=1}(mixer#{mixer_out}, 0, mixer#{mixer_in}, #{j});"
end


last_mixer = l1_mixers + l2_mixers + 1
puts "AudioConnection          patchCord#{patch+=1}(mixer#{last_mixer}, 0, volume_control, 0);"

puts
puts "AudioControlSGTL5000     sgtl5000_1;     //xy=1250,#{keys * 50 + 75}"
puts "AudioOutputI2S           i2s1;           //xy=1250,#{keys * 50 - 25}"
2.times do |i|
  puts "AudioConnection          patchCord#{patch+=1}(volume_control, 0, i2s1, #{i});"
end
puts
puts "// Guitool: End automatically generated code"