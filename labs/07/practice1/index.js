const html = (strings, ...values) => {
	const template = document.createElement("template");
	template.innerHTML = strings.reduce((acc, str, i) => acc + values[i - 1] + str);
	return template.content;
};

const render = (parent, child) => {
	parent.innerHTML = "";
	parent.appendChild(child);
};

const lastfm = document.getElementById("now-playing");

const renderCurrentSong = async () => {
	const data = await fetch("/~a129v447/practice1/api.php");

	const { now_playing: song } = await data.json();

	console.log(song);
	if (song) {
		console.log("Song found!");
		const content = `
		<h4>Now Playing:</h4>
			<a href="${song.url}" target="_blank">
				<div class="box no-shadow">
                    <div class="cluster" style="--justify:start">
                        <img width="65" height="65" class="card__icon" src="${song.cover}" />
						<div class="stack">
							<h4 class="card__title">${song.name}</h4>
							<p class="card__description">${song.artist}</p>
						</div>
					</div>
				</div>
			</a>
		`;

		render(lastfm, html`${content}`);
	}
};

const renderGithub = async () => {
	const github = document.getElementById("projects");

	const data = await fetch("/~a129v447/practice1/api.php");

	const { pinned_repos } = await data.json();

	let content = "";

	for (const repo of pinned_repos) {
		content += `
			<a href="${repo.url}" target="_blank">
				<div class="box no-shadow">
					<div class="cluster">
						<div class="stack">
							<h4 class="card__title">${repo.name}</h4>
							<p class="card__description">${repo.description}</p>
						</div>
					</div>
				</div>
			</a>
		`;
	}

	render(github, html`<div class="grid">${content}</div>`);
};

renderGithub();

(async () => {
	await renderCurrentSong();
	setInterval(async () => {
		console.log("Updating song...");
		await renderCurrentSong();
	}, 30000);
})();
