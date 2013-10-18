package Xfconf::Install::Files;

$self = {
          'inc' => '-I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include   -I. -Ibuild -I/build/src/xfconf-4.10.0/xfconf-perl/.. -I..',
          'typemaps' => [
                          'xfconfperl.typemap'
                        ],
          'deps' => [
                      'Glib'
                    ],
          'libs' => '-L/build/src/xfconf-4.10.0/xfconf-perl/../common/.libs -L/build/src/xfconf-4.10.0/xfconf-perl/../xfconf/.libs -lxfconf-gvaluefuncs -lxfconf-0 -ldbus-glib-1 -lgobject-2.0 -lglib-2.0 -ldbus-1 -lpthread -lrt  '
        };


# this is for backwards compatiblity
@deps = @{ $self->{deps} };
@typemaps = @{ $self->{typemaps} };
$libs = $self->{libs};
$inc = $self->{inc};

	$CORE = undef;
	foreach (@INC) {
		if ( -f $_ . "/Xfconf/Install/Files.pm") {
			$CORE = $_ . "/Xfconf/Install/";
			last;
		}
	}

1;
