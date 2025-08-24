#pragma once
class TimeIntegrator{
    double dt{0.0};

public:
    TimeIntegrator(double DT) { dt = DT; }

    template <class particle_array_t>
        void startIntegration(particle_array_t & parray) {
        // this function moves the initial velocity to -dt/2
        // V = V - A dt/2 = V - F dt /2m
        for (auto & p : parray) {
            for (int ii = 0; ii < 3; ++ii) {
                p.V[ii] = p.V[ii] - p.F[ii]*dt/(2*p.mass);
            }
        }
    }

    template <class particle_array_t>
        void timeStep(particle_array_t & parray) {
        // this function moves the velocity by dt
        for (auto & p : parray) {
            for (int ii = 0; ii < 3; ++ii) {
                p.V[ii] = p.V[ii] + p.F[ii]*dt/p.mass;
                p.R[ii] = p.R[ii] + p.V[ii]*dt;
            }
        }
    }
};
