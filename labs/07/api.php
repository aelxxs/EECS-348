<?php
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');

$xkcd_data = file_get_contents('https://xkcd.com/info.0.json');
$xkcd_json = json_decode($xkcd_data);

echo json_encode($xkcd_json);
?>
