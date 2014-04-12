#!/usr/bin/perl
use strict;
use warnings;
use WWW::Curl::Easy;
use HTML::TreeBuilder;

#get Urls of all the players
my $curl = WWW::Curl::Easy->new;
my $input_url = <STDIN>;
my $team_book = "";
#my $int_url = "http://leetcode.com/2012/05/clone-graph-part-i.html";
my $int_url = $input_url;
my $response_body;
$curl->setopt(CURLOPT_URL, $int_url);
my $temp_html = "temp.html";
open(my $fd,'>',$temp_html) or die "could not open the file";
my $advance_ds = "detail.csv";
open(my $fh_,'>>',$advance_ds) or die "could not open the file";
$curl->setopt(CURLOPT_WRITEDATA,$fd);
my $retcode = $curl->perform;
if ($retcode == 0) {
        my $response_code = $curl->getinfo(CURLINFO_HTTP_CODE);
        close $fd; 
        my $tree = HTML::TreeBuilder->new;
        my $int_root =$tree->parse_file($temp_html);
        my @title_info =  $int_root->look_down('_tag'=>'blockquote');
        for my $title_ (@title_info) {
             my $link_= $title_->as_text() . "\n";
             $fh_->print($link_);
        }
        close $fh_;
} else {                                                                                       
        # Error code, type of error, error message
        print("An error happened: $retcode ".$curl->strerror($retcode)." ".$curl->errbuf."\n");
}
