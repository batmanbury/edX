class Dessert
  attr_accessor :name, :calories

  def initialize(name, calories)
    @name = name
    @calories = calories
  end
  
  def healthy?
    @calories < 200
  end
  
  def delicious?
    true
  end

end

class JellyBean < Dessert
  attr_accessor :flavor

  def initialize(flavor)
    @flavor = flavor
    @name = "#{flavor} jelly bean"
    @calories = 5
  end

  def delicious?
    return true unless @flavor == 'licorice'
    false
  end

end

if __FILE__ == $0
  j = JellyBean.new('vanilla')
  puts j.name
  puts j.delicious?
  k = Dessert.new('cake', 150)
  puts k.name
  puts k.delicious?
  l = JellyBean.new('licorice')
  puts l.name
  puts l.delicious?
end