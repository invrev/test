#!/usr/bin/perl
use strict;
use warnings;
use WWW::Curl::Easy;
use HTML::TreeBuilder;

#get Urls of all the players
my $curl = WWW::Curl::Easy->new;
my $base_url = "http://leetcode.com/page";
my $team_book = "";
my @pages = (1,2,3,4);
for my $page (@pages)  
{
    my $append_url = "/".$page;
    #if 1 then discard page
    my $int_url = $base_url . $append_url;
    my $response_body;
    $curl->setopt(CURLOPT_URL, $int_url);
    my $temp_html = "temp.html";
    open(my $fd,'>',$temp_html) or die "could not open the file";
    my $advance_ds = "advance_ds.csv";
    open(my $fh_,'>>',$advance_ds) or die "could not open the file";
    $curl->setopt(CURLOPT_WRITEDATA,$fd);
    my $retcode = $curl->perform;
    if ($retcode == 0) {
            my $response_code = $curl->getinfo(CURLINFO_HTTP_CODE);
            close $fd; 
            my $tree = HTML::TreeBuilder->new;
            my $int_root =$tree->parse_file($temp_html);
            my @title_info =  $int_root->look_down (class => 'posttitle');
            for my $title_ (@title_info) {
                my @ts = $title_->look_down('_tag'=> 'a');
                for my $link_ (@ts) {
                    #print "links : ",$link_->attr('href'). "\n";
                    my $link_ = $link_->attr('href'). "\n";
                    $fh_->print($link_);
                }
            }
            close $fh_;
    } else {                                                                                       
            # Error code, type of error, error message
            print("An error happened: $retcode ".$curl->strerror($retcode)." ".$curl->errbuf."\n");
    }

}

