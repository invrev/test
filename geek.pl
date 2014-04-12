#!/usr/bin/perl
use strict;
use warnings;
use WWW::Curl::Easy;
use HTML::TreeBuilder;

#get Urls of all the players
my $curl = WWW::Curl::Easy->new;
my $base_team_url = "http://www.geeksforgeeks.org/tag/advance-data-structures/";
my $team_book = "";
my @pages = (1);
for my $page (@pages)  
{
    my $append_url = "page/".$page ."/";
    #if 1 then discard page
    my $int_url = $base_team_url . $append_url;
    $int_url = "http://www.geeksforgeeks.org/tag/Greedy-Algorithm/";
    #print "interview url = " ,$int_url ,"\n";
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
            print $int_root;
            my @title_lst = $int_root->look_down('_tag' => 'h2');
            for my $title_ (@title_lst) {
                my @ts = $title_->look_down('_tag'=> 'a');
                for my $link_ (@ts) {
                    print "links : ",$link_->attr('href'). "\n";
                }
                #print $links_r;
            }
            #my @groom_abs_arr_2 =  $groom_root->look_down (class => 'text_list2');
            #for my $groom_info (@groom_abs_arr_2) {
            #    #print join '^I', map(ref($_) ? $_->as_text: $_,$groom_info->content_list);
            #    #print "\n";
            #    $fh_->print(join '^I', map(ref($_) ? $_->as_text: $_,$groom_info->content_list));
            #    $fh_->print("\n");
            #}
            #close $fh_;

    } else {                                                                                       
            # Error code, type of error, error message
            print("An error happened: $retcode ".$curl->strerror($retcode)." ".$curl->errbuf."\n");
    }

}

