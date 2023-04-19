<?php
header('Content-Type: text/html; charset=utf-8');
header('Access-Control-Allow-Origin: *');

$size = isset($_GET['size']) ? intval($_GET['size']) : 1;

if ($size <= 0) {
    echo 'Invalid size';
    exit;
}

echo '<link rel="stylesheet" href="../styles/reset.css" />';
echo '<link rel="stylesheet" href="../styles/style.css" />';

echo '<div class="stack">';
echo '<a href="/"><small>👈 click to go back</small></a>';

echo '<div class="box">';
echo '<table border="1">';
echo '<tr><th></th>';
for ($i = 1; $i <= $size; $i++) {
    echo '<th>' . $i . '</th>';
}
echo '</tr>';

for ($i = 1; $i <= $size; $i++) {
    echo '<tr><th>' . $i . '</th>';
    for ($j = 1; $j <= $size; $j++) {
        echo '<td>' . $i * $j . '</td>';
    }
    echo '</tr>';
}

echo '</table>';
echo '</div></div>';

exit;

?>
