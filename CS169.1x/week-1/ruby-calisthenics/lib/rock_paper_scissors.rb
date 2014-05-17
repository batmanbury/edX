class RockPaperScissors

  # Exceptions this class can raise:
  class NoSuchStrategyError < StandardError ; end

  def self.winner(player1, player2)
    strategies = ['R','P','S']
    unless ([player1[1], player2[1]] - strategies).empty?
      raise NoSuchStrategyError, 'Strategy must be one of R,P,S'
    end
    return player1 if player1[1] == player2[1]
    case player1[1]
      when 'R'
        return player1 if player2[1] == 'S'
        player2
      when 'P'
        return player1 if player2[1] == 'R'
        player2
      when 'S'
        return player1 if player2[1] == 'P'
        player2
    end
  end

  def self.tournament_winner(tournament)
    t = tournament.flatten.length
    if t == 4
      self.winner(tournament[0], tournament[1])
    else
      bracket_1 = self.tournament_winner(tournament[0])
      bracket_2 = self.tournament_winner(tournament[1])
      self.winner(bracket_1, bracket_2)
    end
  end

end


if __FILE__ == $0

  tourney = [
              [
                [ ["Armando", "P"], ["Dave", "S"] ],      
                [ ["Richard", "R"], ["Michael", "S"] ]
              ],
              [
                [ ["Allen", "S"], ["Omer", "P"] ],
                [ ["David E.", "R"], ["Richard X.", "P"] ]
              ]
            ]
  puts RockPaperScissors.tournament_winner(tourney)

end