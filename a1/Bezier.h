#ifndef BEZIER_H
#define BEZIER_H
#include "foundation.h"

class BezierSpline
{
public:
    BezierSpline() { BernsteinCoef = BinomialCoef = NULL; degree = 0; }
    ~BezierSpline() { delete BernsteinCoef; delete BinomialCoef; }

    virtual double ParametricStart() { return 0.0; }
    virtual double ParametricEnd() { return 1.0; }

    virtual void SetControlPoints(const std::vector<Vec2d> & CPList)
    {
        cpList.assign(CPList.begin(), CPList.end());
        PrepareBernstein((int)CPList.size() - 1);
    }

    virtual const Vec2d Sample(double parametricPosition)
    {
        Vec2d Result;
        if (cpList.size() == 0 || degree < 1) return Result;
        if ((parametricPosition < 0) || (parametricPosition > 1)) return Result;

        //TODO: sample the point on the Bezier spline of the requested parametric position

        return Result;
    }

private:
    std::vector<Vec2d> cpList;
    double * BernsteinCoef;
    double * BinomialCoef;
    int degree;
    void PrepareBernstein(int deg)
    {
        if (deg < 1) return;

        if (deg != degree)
        {
            //TODO: Allocate the required space and pre-compute binomila coefficients.

        }
    }

    int pow(int n)
    {
        int result = 1;
        for (int i = 1; i <= n; ++ i) result = result * i;
        return result;
    }
};

#endif // BEZIER_H
