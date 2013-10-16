#
# Copyright (c) 2008 Brian Tarricone <bjt23@cornell.edu>
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; version 2 of the License ONLY.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

{ package Xfce4::Xfconf;
    use 5.008;
    use strict;
    use warnings;
    
    use Glib;
    
    require DynaLoader;
    
    our $VERSION = '4.10.0';
    
    our @ISA = qw(DynaLoader);
    
    sub import {
        my $class = shift;
        $class->VERSION(@_);
    }
    
    # this next bit causes problems on darwin, hence the conditional
    sub dl_load_flags {
        return $^O eq 'darwin' ? 0x00 : 0x01;
    }
    
    # and we're off
    Xfce4::Xfconf->bootstrap($VERSION);
}

1;
__END__

=head1 NAME

Xfconf - Perl interface to the Xfconf configuration system.

=head1 SYNOPSIS

  use Xfce4::Xfconf;
  
  my $channel = Xfce4::Xfconf::Channel->new('FooChannel');
  my $value = $channel->get_string('/general/foo-property');

=head1 ABSTRACT

Perl bindings to the Xfconf confgiuration system.  This module allows
you to access settings stored in Xfconf using perl.

=head1 DESCRIPTION

The Xfce4::Xfconf module allows perl developers to make use of the
Xfconf configuration system to store and retrieve settings for perl
applications.  Learn more about Xfce and Xfconf at http://xfce.org/.

The Xfconf API reference is very useful when writing apps using xfconf-perl.
The call signatures will not always be identical, but one can get a good idea
of what the different functions and classes do:
http://mocha.xfce.org/~kelnos/xfconf/docs-current/

To discuss xfconf-perl, please join the Xfce Development Discussion list.
Instructions can be found at http://foo-projects.org/mailman/listinfo/xfce4-dev

Finally, the xfconf-perl website is located at:
http://xfce.org/

=head1 AUTHORS

  Brian Tarricone <bjt23@cornell.edu>

=head1 COPYRIGHT AND LICENSE

Copyright (c) 2008 Brian Tarricone <bjt23@cornell.edu>.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA  02111-1307  USA.

=cut
