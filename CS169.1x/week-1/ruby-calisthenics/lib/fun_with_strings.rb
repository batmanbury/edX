module FunWithStrings
  def palindrome?
    flat_text = self.downcase.gsub(/\W*/, '')
    flat_text.reverse == flat_text
  end
  def count_words
    no_punc = self.downcase.gsub(/\W+/, ' ')
    words = no_punc.split(' ')
    counts = Hash.new 0
    words.each do |word|
      counts[word] += 1
    end
    counts
  end
  def anagram_groups
    words = self.split(" ")
    chars_sorted = words.map{ |w| w.downcase.chars.sort.join }.uniq
    anagrams = Hash[chars_sorted.map { |cs| [cs, []] } ]
    words.each { |w| anagrams[w.downcase.chars.sort.join] << w }
    anagrams.values
  end
end

# make all the above functions available as instance methods on Strings:

class String
  include FunWithStrings
end
