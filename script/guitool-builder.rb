keys = 24
patch = 0

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
(keys / 2).times do |i|
  n = i + 1
  puts "AudioMixer4              mixer#{n};         //xy=450,#{i * 200 + 75}"
end

puts
(keys / 8).times do |i|
  n = i + 1 + keys / 2
  puts "AudioMixer4              mixer#{n};         //xy=650,#{i * 800 + 375}"
end

puts
puts "AudioMixer4              mixer#{keys/2 + keys/8 + 1};         //xy=850,#{keys * 50 - 25}"

puts
keys.times do |i|
  n = i + 1
  puts "AudioConnection          patchCord#{patch+=1}(waveform#{n}, envelope#{n});"
end

(keys / 4).times do |i|
  n = i + 1
  4.times do |j|
    env = 1 + i * 4 + j
    puts "AudioConnection          patchCord#{patch+=1}(envelope#{env}, 0, mixer#{n}, #{j});"
  end
end

puts
(keys / 4).times do |i|
  n = i + 7
  4.times do |j|
    wt = 1 + i * 4 + j
    puts "AudioConnection          patchCord#{patch+=1}(wavetable#{wt}, 0, mixer#{n}, #{j});"
  end
end

puts
(keys / 8).times do |i|
  mixer_out = 1 + i + keys / 2
  4.times do |j|
    mixer_in = 1 + i * 4 + j
    puts "AudioConnection          patchCord#{patch+=1}(mixer#{mixer_in}, 0, mixer#{mixer_out}, #{j});"
  end
end

mixer_out = keys/2 + keys/8 + 1
(keys / 8).times do |i|
  mixer_in = keys/2 + 1 + i
  puts "AudioConnection          patchCord#{patch+=1}(mixer#{mixer_in}, 0, mixer#{mixer_out}, #{i});"
end

puts
puts "AudioControlSGTL5000     sgtl5000_1;     //xy=1050,#{keys * 50 + 75}"
puts "AudioOutputI2S           i2s1;           //xy=1050,#{keys * 50 - 25}"
2.times do |i|
  puts "AudioConnection          patchCord#{patch+=1}(mixer#{mixer_out}, 0, i2s1, #{i});"
end