const verifyPassword = (e) => {
	e.preventDefault();

	const form = document.getElementById("form");

	const data = new FormData(form);

	const passwordOne = data.get("passwordOne");
	const passwordTwo = data.get("passwordTwo");

	if (passwordOne !== passwordTwo) {
		return alert("Passwords do not match!");
	}

	if (passwordOne.length < 8 || passwordTwo.length < 8) {
		return alert("Password is too short!");
	}

	alert("Passwords match!");
};
