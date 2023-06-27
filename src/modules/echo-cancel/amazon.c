#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <pulse/cdecl.h>

PA_C_DECL_BEGIN
#include <pulsecore/core-util.h>
#include <pulsecore/modargs.h>
#include "echo-cancel.h"
PA_C_DECL_END

bool pa_amazon_ec_init(pa_core *c, pa_echo_canceller *ec,
                     pa_sample_spec *rec_ss, pa_channel_map *rec_map,
                     pa_sample_spec *play_ss, pa_channel_map *play_map,
                     pa_sample_spec *out_ss, pa_channel_map *out_map,
                     uint32_t *nframes, const char *args) {
    char strss_source[PA_SAMPLE_SPEC_SNPRINT_MAX];
    char strss_sink[PA_SAMPLE_SPEC_SNPRINT_MAX];

    *nframes = 256;
    ec->params.null.out_ss = *out_ss;

    *rec_ss = *out_ss;
    *rec_map = *out_map;

    pa_log("Amazon AEC: nframes=%u, sample spec source=%s, sample spec sink=%s", *nframes,
                 pa_sample_spec_snprint(strss_source, sizeof(strss_source), out_ss),
                 pa_sample_spec_snprint(strss_sink, sizeof(strss_sink), play_ss));

    return true;
}

void pa_amazon_ec_run(pa_echo_canceller *ec, const uint8_t *rec, const uint8_t *play, uint8_t *out) {
    /* The null implementation simply copies the recorded buffer to the output
       buffer and ignores the play buffer. */
    pa_log("Run Amazon EC...");
    memcpy(out, rec, 256 * pa_frame_size(&ec->params.null.out_ss));
    pa_log("Finished running Amazon EC...");
}

void pa_amazon_ec_done(pa_echo_canceller *ec) {
}