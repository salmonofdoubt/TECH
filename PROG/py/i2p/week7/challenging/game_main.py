from games import guessing_game

def main():
  my_game = guessing_game.GuessingGame(14,12,13,5)
  my_game.Guessint(3)

  my_game.ShowFailedMsg()

if __name__ == '__main__':
	main()
	
