const handle = (e) => {
	e.preventDefault();

	const form = e.target;
	const data = new FormData(form);

	const width = data.get("borderWidth");

	const [borderR, borderG, borderB] = [data.get("borderColorR"), data.get("borderColorG"), data.get("borderColorB")];

	const borderColor = `rgb(${borderR}, ${borderG}, ${borderB})`;

	const [backgroundR, backgroundG, backgroundB] = [
		data.get("backgroundColorR"),
		data.get("backgroundColorG"),
		data.get("backgroundColorB"),
	];

	const backgroundColor = `rgb(${backgroundR}, ${backgroundG}, ${backgroundB})`;

	console.log(width, borderColor, backgroundColor);

	const box = document.getElementById("box");

	box.style.borderWidth = width + "px";
	box.style.borderColor = borderColor ?? "var(--border-color)";
	box.style.backgroundColor = backgroundColor ?? "var(--background-color)";
};
