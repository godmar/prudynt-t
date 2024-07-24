#ifndef IMPServerMediaSubsession_hpp
#define IMPServerMediaSubsession_hpp

#include "StreamReplicator.hh"
#include "ServerMediaSession.hh"
#include "OnDemandServerMediaSubsession.hh"
#include "Encoder.hpp"

class IMPServerMediaSubsession: public OnDemandServerMediaSubsession {
public:
    static IMPServerMediaSubsession* createNew(
        UsageEnvironment& env,
        H264NALUnit* vps,  // Change to pointer for optional VPS
        H264NALUnit sps,
        H264NALUnit pps
    );
protected:
    // Constructor with VPS as a pointer for optional usage
    IMPServerMediaSubsession(
        UsageEnvironment& env,
        H264NALUnit* vps,  // Change to pointer for optional VPS
        H264NALUnit sps,
        H264NALUnit pps
    );
    virtual ~IMPServerMediaSubsession();

protected:
    virtual FramedSource* createNewStreamSource(
        unsigned clientSessionId,
        unsigned& estBitrate
    ) override;
    virtual RTPSink* createNewRTPSink(
        Groupsock* rtpGroupsock,
        unsigned char rtpPayloadTypeIfDynamic,
        FramedSource* inputSource
    );

private:
    StreamReplicator* replicator;
    H264NALUnit* vps; // Change to pointer for optional VPS
    H264NALUnit sps, pps;
};

#endif // IMPServerMediaSubsession_hpp
