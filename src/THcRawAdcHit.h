#ifndef ROOT_THcRawAdcHit
#define ROOT_THcRawAdcHit

#include "TObject.h"


class THcRawAdcHit : public TObject {
  public:
    THcRawAdcHit();
    THcRawAdcHit& operator=(const THcRawAdcHit& right);
    virtual ~THcRawAdcHit();

    virtual void Clear(Option_t* opt="");

    void SetData(Int_t data);
    void SetSample(Int_t data);
    void SetDataTimePedestalPeak(
      Int_t data, Int_t time, Int_t pedestal, Int_t peak
    );

    Int_t GetRawData(UInt_t iPulse=0) const;
    Double_t GetF250_PeakPedestalRatio() {return fPeakPedestalRatio;};

    Double_t GetAverage(UInt_t iSampleLow, UInt_t iSampleHigh) const;
    Int_t GetIntegral(UInt_t iSampleLow, UInt_t iSampleHigh) const;
    Double_t GetData(
      UInt_t iPedLow, UInt_t iPedHigh, UInt_t iIntLow, UInt_t iIntHigh
    ) const;

    UInt_t GetNPulses() const;
    UInt_t GetNSamples() const;

    Bool_t HasMulti() const;

    Int_t GetPedRaw() const;
    Int_t GetPulseIntRaw(UInt_t iPulse=0) const;
    Int_t GetPulseAmpRaw(UInt_t iPulse=0) const;
    Int_t GetPulseTimeRaw(UInt_t iPulse=0) const;
    Int_t GetSampleRaw(UInt_t iSample=0) const;

    Double_t GetPed() const;
    Double_t GetPulseInt(UInt_t iPulse=0) const;
    Double_t GetPulseAmp(UInt_t iPulse=0) const;
    //Int_t GetPulseTime(UInt_t iPulse=0) const;
    //Int_t GetSample(UInt_t iSample=0) const;

    Int_t GetSampleIntRaw() const;
    Double_t GetSampleInt() const;

    void SetF250Params(Int_t NSA, Int_t NSB, Int_t NPED);

  protected:
    static const UInt_t fMaxNPulses = 4;
    static const UInt_t fMaxNSamples = 511;

    Int_t fNPedestalSamples;  // TODO: Get this from prestart event...
    Int_t fNPeakSamples;
    Double_t fPeakPedestalRatio;
    Double_t fSubsampleToTimeFactor;

    Int_t fPed;
    Int_t fPulseInt[fMaxNPulses];
    Int_t fPulseAmp[fMaxNPulses];
    Int_t fPulseTime[fMaxNPulses];
    Int_t fSample[fMaxNSamples];

    Bool_t fHasMulti;
    UInt_t fNPulses;
    UInt_t fNSamples;

  private:
    ClassDef(THcRawAdcHit, 0)
};


#endif  // ROOT_THcRawAdcHit
