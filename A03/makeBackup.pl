#!/bin/perl -w
# This program copies a the files supplied as arguments to
# a backup directory with the date and time appended to the
# top of the file.
my $time = localtime;
$args = @ARGV;

die "Please enter an argument." unless $args > 0;

for (my $i = 0; $i < $args; $i++) {
    my $filename = $ARGV[$i];
    system("touch backup/$filename.old; echo $time > backup/$filename.old;");
    system("cat $filename >> backup/$filename.old;");
}
