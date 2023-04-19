const fetchCurrentXKXD = async () => {
	const data = await fetch("/~a129v447/api.php");
	return await data.json();
};

(async () => {
	const comic = document.querySelector("#comic");

	const { img, title } = await fetchCurrentXKXD();

	comic.src = img;
	comic.alt = title;
})();
