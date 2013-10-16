#ifndef rr__version_h
#define rr__version_h

#define RR_MAJOR_VERSION 3
#define RR_MINOR_VERSION 5
#define RR_MICRO_VERSION 30
#define RR_VERSION RR_MAJOR_VERSION.RR_MINOR_VERSION.RR_MICRO_VERSION

#define RR_CHECK_VERSION(major,minor,micro) \
    (RR_MAJOR_VERSION > (major) || \
     (RR_MAJOR_VERSION == (major) && RR_MINOR_VERSION > (minor)) || \
     (RR_MAJOR_VERSION == (major) && RR_MINOR_VERSION == (minor) && \
      RR_MICRO_VERSION >= (micro)))

#endif
