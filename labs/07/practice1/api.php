<?php
header('Content-Type: application/json');
header('Access-Control-Allow-Origin: *');
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

$opts = array(
    'http' => array(
        'method' => "GET",
        'header' => "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\n" .
                    "Accept-Language: en-US,en;q=0.5\r\n",
        'ignore_errors' => true,
        'timeout' => 10
    ),
    'ssl' => array(
        'verify_peer' => false,
        'verify_peer_name' => false
    )
);

$context = stream_context_create($opts);

$alexis_data = file_get_contents('https://alexis.lol/api/now_playing', false, $context);
$alexis_json = json_decode($alexis_data);

$repos = file_get_contents('https://ghapi.dstn.to/aelxxs/pinned', false, $context);
$repos_json = json_decode($repos);


$response = array(
    'now_playing' => $alexis_json->song,
    'pinned_repos' => $repos_json->data
);


echo json_encode($response);
?>
