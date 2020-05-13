// BY Nicholas Osafo Adamu
// Compute hand landmark similarity using weighted matching
// from https://medium.com/tensorflow/move-mirror-an-ai-experiment-with-pose-estimation-in-the-browser-using-tensorflow-js-2f7b769f9b23

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
constexpr char recognizedHandGestureTag[] = "RECOGNIZED_HAND_GESTURE";
} // namespace
class RecognizerWeightedMatch : public CalculatorBase
{
public:
    RecognizerWeightedMatch(){};
    // ~GestureRecognizerCalculator() override{};

    static ::mediapipe::Status GetContract(CalculatorContract *cc);

    ::mediapipe::Status Open(CalculatorContext *cc) override;

    ::mediapipe::Status Process(CalculatorContext *cc) override;

private:
    float weighted_match(NormalizedLandmarkList stored, NormalizedLandmarkList current)
    {
        float dist;
        return dist;
    }
};

} // namespace mediapipe