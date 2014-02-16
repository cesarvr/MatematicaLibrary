//
//  Vector3.h
//  MatProyecto
//
//  Created by Cesar Luis Valdez on 16/02/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __MatProyecto__Vector3__
#define __MatProyecto__Vector3__

#include <iostream>
#include "Precision.h"

namespace Matematica {

    
    class Vector3{
        
    public:
        real x, y ,z;
        
        Vector3(): x(0), y(0), z(0) {}
        Vector3(const real x, const real y, const real z): x(x), y(y), z(z) {}
        
        void invertir(){
            x=-x;
            y=-y;
            z=-z;
        }
        
        real tamano() const{
        
            return real_sqrt( x*x + y*y + z*z);
        }
        
        
        void normalizar(){
        
            real tmn = tamano();
            
            if(tmn > 0){
                (*this)*=((real)1)/l;
            }
            
        }
        
        
        /*
            Operaciones aritmeticas.
        
            Escalar * vector
         */
        
        
        Vector3 operator*=( const real valor ){
            x *= valor;
            y *= valor;
            z *= valor;
        }
        
        Vector3 operator*(const real valor) const{
        
            return Vector3(x*valor, y*valor, z*valor);
        }
        
        
        /* 
            adicion, substraccion.
         */
        
        void operator+=(const Vector3& v){
            x+=v.x; y+=v.y; z+=v.z;
        
        }
        
        Vector3 operator+(const Vector3& v) const
        {
            return Vector3(x+v.x, y+v.y, z+v.z);
        }
        
        
        
        /** Subtracts the given vector from this. */
        void operator-=(const Vector3& v)
        {
            x -= v.x; y -= v.y; z -= v.z;
        }
        /**
         * Returns the value of the given vector subtracted from this. */
        Vector3 operator-(const Vector3& v) const
        {
            return Vector3(x-v.x, y-v.y, z-v.z);
        
        }
        
        /**
         * Añadir vector escalado o axpy.
         */
        void smrVectorEscalado(const Vector3& vector, real scale) {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }
        
        real dot(const Vector3& v) const{
        
            return x*v.x + y*v.y + z*v.z;
        
        }
        
        
    };


}



#endif /* defined(__MatProyecto__Vector3__) */
