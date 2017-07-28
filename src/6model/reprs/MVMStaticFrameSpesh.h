/* Representation used for holding specializer (dynamic optimization) data
 * about a static frame (logged statistics, generated specializations, and
 * so forth). */

struct MVMStaticFrameSpeshBody {
    /* Specializations array, if there are any. Candidates themselves never
     * move in memory; the array of pointers to them is managed using the
     * fixed size allocator and freed at the next safepoint. */
    MVMSpeshCandidate **spesh_candidates;
    MVMuint32 num_spesh_candidates;

    /* Recorded count for data recording for the specializer. Incremented
     * until the recording threshold is reached, and may be cleared by the
     * specialization worker later if it wants more data recorded. Allowed
     * to be a bit racey between threads; it's not a problem if we get an
     * extra recording or so. */
    MVMuint32 spesh_entries_recorded;
};
struct MVMStaticFrameSpesh {
    MVMObject common;
    MVMStaticFrameSpeshBody body;
};

/* Function for REPR setup. */
const MVMREPROps * MVMStaticFrameSpesh_initialize(MVMThreadContext *tc);