#!/usr/bin/php
<?php
    
    // php function scrapes a celestrak location for url details
    // written by Kingsley Kwadwo Oteng-Amoako
    // January 29th, 2020
    // for example, $url = "https://celestrak.com/satcat/tle.php?CATNR=43108";
    $url = $argv[1];

    //Code to write url contents to a file...
    $data = file_get_contents($url);

    //save by filename as cotents html
    $filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/resource.html";

    //save the file
    $fh = fopen($filename,"w");
    fwrite($fh,$data);
    fclose($fh);
    
?>
