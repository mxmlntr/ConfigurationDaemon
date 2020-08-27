#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER tp_provider

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./time-tp.h"

#if !defined(_time_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _time_TP_H

#include <lttng/tracepoint.h>

//! Defines if tracing is enabled
//! This define depends on define NEWFILE from process_manager.h
//#define TRACENEWFILE
//#define TRACEOLDFILE

TRACEPOINT_EVENT(
        tp_provider,
        time_tracepoint_daemon_old,
        TP_ARGS(
                int, probe_nr
        ),
        TP_FIELDS(
                ctf_integer(int, probeNumber, probe_nr)
        )
)

TRACEPOINT_EVENT(
        tp_provider,
        time_tracepoint_daemon_new,
        TP_ARGS(
                int, probe_nr
        ),
        TP_FIELDS(
                ctf_integer(int, probeNumber, probe_nr)
        )
)

#endif /* _time_TP_H */

#include <lttng/tracepoint-event.h>