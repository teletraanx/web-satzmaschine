createSatzmaschineModule().then((Module) => {
  const sentence = document.getElementById("sentence");
  const button = document.getElementById("generateButton");
  const currentWords = document.getElementById("currentWords");

  function showNewSentence() {
    sentence.textContent = Module.generateSentence();

    const wordsText = Module.getCurrentWords();
    const words = wordsText
      .trim()
      .split("\n")
      .filter(Boolean);

    currentWords.innerHTML = "";

    for (const item of words) {
      const [german, english] = item.split("|");

      const li = document.createElement("li");
      li.innerHTML = `<span>${german}</span> — ${english}`;
      currentWords.appendChild(li);
    }
  }

  showNewSentence();

  button.addEventListener("click", showNewSentence);
});