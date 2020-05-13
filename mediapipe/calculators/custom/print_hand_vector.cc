#include "mediapipe/framework/calculator_framework.h"
#include "mediapipe/framework/formats/landmark.pb.h"
#include "mediapipe/framework/formats/rect.pb.h"
#include <cmath>

namespace mediapipe
{
namespace
{
constexpr char normRectTag[] = "NORM_RECT";
constexpr char normalizedLandmarkListTag[] = "NORM_LANDMARKS";
constexpr char landmarkListTag[] = "LANDMARK_LIST";

} // namespace
class PrintHandVectorCalculator : public CalculatorBase
{
public:
    PrintHandVectorCalculator(){};
    // ~GestureRecognizerCalculator() override{};

    static ::mediapipe::Status GetContract(CalculatorContract *cc);

    ::mediapipe::Status Open(CalculatorContext *cc) override;

    ::mediapipe::Status Process(CalculatorContext *cc) override;
};

::mediapipe::Status PrintHandVectorCalculator::GetContract(CalculatorContract *cc)
{
    // Checks if input stream has the normalizedLandmarkListTag
    RET_CHECK(cc->Inputs().HasTag(normalizedLandmarkListTag));
    // Set normalizedLandmarkListTag to receive a NormalizedLandmarkList as input
    cc->Inputs().Tag(normalizedLandmarkListTag).Set<NormalizedLandmarkList>();

    // Checks if input stream has the normRectTag
    RET_CHECK(cc->Inputs().HasTag(normRectTag));
    // Set normRectTag to receive a NormalizedRect as input
    cc->Inputs().Tag(normRectTag).Set<NormalizedRect>();

    // Check if output stream has tag landmarkListTag
    RET_CHECK(cc->Outputs().HasTag(landmarkListTag));
    // Set output stream to recognizedHandGesture string
    cc->Outputs().Tag(landmarkListTag).Set<std::string>();

    return ::mediapipe::OkStatus();
}

::mediapipe::Status PrintHandVectorCalculator::Open(CalculatorContext *cc)
{
    // Must look into this carefully
    cc->SetOffset(TimestampDiff(0));
    return ::mediapipe::OkStatus();
}

::mediapipe::Status PrintHandVectorCalculator::Process(CalculatorContext *cc)
{
    const auto &output_landmarks = cc->Inputs().Tag(normalizedLandmarkListTag).Get<NormalizedLandmarkList>();
    output_landmarks.DebugString();

    return ::mediapipe::OkStatus();
   
    // cc->Outputs().Tag(landmarkListTag).Add("HI", cc->InputTimestamp());
}
} // namespace mediapipe