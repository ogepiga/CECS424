#!/usr/bin/ruby


class Board
attr_reader :matrix

def initialize
  @matrix = Array.new(6, nil)
  for i in 0..@matrix.length - 1
    matrix[i] = Array.new(8, " ")
  end
end

def printing
  @matrix.each do |row|
    print row.join("|")
    print "\n"
  end
end

end

class Game

#initializing the game
def initialize(player_1, player_2)
  @player_1 = player_1
  @player_2 = player_2
  @p1 = player_1[0,1].upcase
  @p2 = player_2[0,1].upcase
  @board =  Board.new
end

#intro for the game
def header (player)
  if player == @p1
    print "Your turn, " + @player_1
  else
    print "Your turn, " + @player_2
  end
  print "Choose a column (0,7): "
  input =  gets.to_i
  if (0..7).include? input
    return input
  else
    puts "Enter a valid column!"
    header(player)
  end
end

#mark the column with an R or Y
def play(column, player)
  for i in (@board.matrix.length - 1).downto(0)
    if @board.matrix[i][column] == " "
      @board.matrix[i][column] = player
      return i
    end
  end
  return -1
end

#checking for winner
def win (row, column, player)
  #checking for 4 in a row
  counter = 0
  for i in 0..@board.matrix[0].length - 1
    if @board.matrix[row][i] == player
      counter += 1
    else
      counter = 0
    end
    if counter >= 4
      return true
    end
  end

  #checking for column
  counter = 0
  for j in 0..@board.matrix.length - 1
    if @board.matrix[j][column] == player
      counter += 1
    else
      counter = 0
    end
    if counter >= 4
      return true
    end
  end

  #checking for bottom right diagonal
  bottom_right = 0
  while true
    r = row + bottom_right + 1
    c = column + bottom_right + 1
    if !defined?(@board.matrix[r][c]) || @board.matrix[r][c] != player
      break
    else
      bottom_right += 1
    end
  end
  #checking for bottom left diagonal
  bottom_left = 0
  while true
    r = row + bottom_left + 1
    c = column - bottom_left - 1
    if !defined?(@board.matrix[r][c]) || @board.matrix[r][c] != player
      break
    else
      bottom_left += 1
    end
  end
  #checking for top right diagonal
  top_right = 0
  while true
    r = row - top_right - 1
    c = column + top_right + 1
    if !defined?(@board.matrix[r][c]) || @board.matrix[r][c] != player
      break
    else
      top_right += 1
    end
  end
  #checking for top left diagonal
  top_left = 0
  while true
    r = row - top_left - 1
    c = column - top_left - 1
    if !defined?(@board.matrix[r][c]) || @board.matrix[r][c] != player
      break
    else
      top_left += 1
    end
  end

  if bottom_right + top_left + 1 >= 4 || bottom_left + top_right + 1 >= 4
    return true
  end

  return false
end

def pturn(player=@p1)
    @board.printing
    player_column = header(player)
    row = self.play(player_column,player)
    if row >= 0
      #check win
      if self.win(row, player_column, player)
        if player == @p1
          print "Congratulations, " + @player_1
        else
          print "Congratulations, " + @player_2 + " you win!"
        end
        return
      end
      #In case no one wins
      if player == @p1
        pturn(@p2)
      else
        pturn(@p1)
      end
    else
      puts "Invalid move, try again!"
      pturn(player)
    end
 end
end

print "Player 1: "
player_1 = gets
print "Player 2: "
player_2 = gets
game = Game.new(player_1, player_2)
game.pturn
