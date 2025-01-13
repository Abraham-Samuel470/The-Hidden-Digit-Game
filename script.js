let maxNumber, maxAttempts, targetNumber, remainingAttempts;
let gamesPlayed = 0, gamesWon = 0, gamesLost = 0;

function showDifficultyScreen() {
    document.getElementById('welcome-screen').classList.add('hidden');
    document.getElementById('difficulty-screen').classList.remove('hidden');
}

function startGame(number, attempts) {
    maxNumber = number;
    maxAttempts = attempts;
    targetNumber = Math.floor(Math.random() * maxNumber) + 1;
    remainingAttempts = maxAttempts;
    document.getElementById('difficulty-screen').classList.add('hidden');
    document.getElementById('gameplay-screen').classList.remove('hidden');
    document.getElementById('instructions').innerText = `I have selected a number between 1 and ${maxNumber}. You have ${maxAttempts} attempts.`;
    updateProgressBar();
}

function submitGuess() {
    const guess = parseInt(document.getElementById('guess-input').value);
    if (isNaN(guess) || guess < 1 || guess > maxNumber) {
        document.getElementById('feedback').innerText = `Please enter a valid number between 1 and ${maxNumber}.`;
        return;
    }

    remainingAttempts--;
    updateProgressBar();

    if (guess < targetNumber) {
        document.getElementById('feedback').innerText = 'Too low!';
    } else if (guess > targetNumber) {
        document.getElementById('feedback').innerText = 'Too high!';
    } else {
        document.getElementById('feedback').innerText = '';
        endGame(true);
        return;
    }

    if (remainingAttempts === 0) {
        endGame(false);
    }
}

function updateProgressBar() {
    const progress = (remainingAttempts / maxAttempts) * 100;
    document.getElementById('progress-fill').style.width = `${progress}%`;
}

function endGame(won) {
    document.getElementById('gameplay-screen').classList.add('hidden');
    document.getElementById('end-screen').classList.remove('hidden');
    gamesPlayed++;

    if (won) {
        document.getElementById('end-message').innerText = `Congratulations! You guessed the number ${targetNumber}.`;
        gamesWon++;
    } else {
        document.getElementById('end-message').innerText = `Game Over! The number was ${targetNumber}.`;
        gamesLost++;
    }

    updateScoreboard();
}

function resetGame() {
    document.getElementById('end-screen').classList.add('hidden');
    document.getElementById('welcome-screen').classList.remove('hidden');
}

function updateScoreboard() {
    document.getElementById('games-played').innerText = gamesPlayed;
    document.getElementById('games-won').innerText = gamesWon;
    document.getElementById('games-lost').innerText = gamesLost;
}
