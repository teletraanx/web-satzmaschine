createSatzmaschineModule().then((Module) => {
  const sentence = document.getElementById("sentence");
  const button = document.getElementById("generateButton");

  sentence.textContent = Module.generateSentence();

  button.addEventListener("click", () => {
    sentence.textContent = Module.generateSentence();
  });
});