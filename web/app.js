createSatzmaschineModule().then((Module) => {
  const sentenceElement =
    document.getElementById("sentence");

  const generateButton =
    document.getElementById("generateButton");

  const currentWordsElement =
    document.getElementById("currentWords");

  const levelMessageElement =
    document.getElementById("levelMessage");

  const levelCheckboxes =
    document.querySelectorAll(".level-checkbox");

  function getSelectedLevels() {
    return Array.from(levelCheckboxes)
      .filter((checkbox) => checkbox.checked)
      .map((checkbox) => checkbox.value)
      .join(",");
  }

  function updateCurrentWords() {
    const wordsText = Module.getCurrentWords();

    const words = wordsText
      .trim()
      .split("\n")
      .filter(Boolean);

    currentWordsElement.innerHTML = "";

    for (const item of words) {
      const separatorPosition = item.indexOf("|");

      if (separatorPosition === -1) {
        continue;
      }

      const german =
        item.substring(0, separatorPosition);

      const english =
        item.substring(separatorPosition + 1);

      const listItem =
        document.createElement("li");

      const germanWord =
        document.createElement("span");

      germanWord.textContent = german;

      listItem.appendChild(germanWord);
      listItem.append(` — ${english}`);

      currentWordsElement.appendChild(listItem);
    }
  }

  function showNewSentence() {
    const selectedLevels = getSelectedLevels();

    if (selectedLevels.length === 0) {
      sentenceElement.textContent =
        "Select at least one level.";

      currentWordsElement.innerHTML = "";

      levelMessageElement.textContent =
        "Please activate a practice level.";

      return;
    }

    levelMessageElement.textContent = "";

    sentenceElement.textContent =
      Module.generateSentence(selectedLevels);

    updateCurrentWords();
  }

  generateButton.addEventListener(
    "click",
    showNewSentence
  );

  for (const checkbox of levelCheckboxes) {
    checkbox.addEventListener("change", () => {
      if (getSelectedLevels().length === 0) {
        levelMessageElement.textContent =
          "Please activate a practice level.";
      }
      else {
        levelMessageElement.textContent = "";
      }
    });
  }

  showNewSentence();
});