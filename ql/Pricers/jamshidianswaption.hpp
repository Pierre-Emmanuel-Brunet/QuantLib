
/*
 Copyright (C) 2001, 2002, 2003 Sadruddin Rejeb

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file jamshidianswaption.hpp
    \brief Swaption pricer using Jamshidian's decomposition
*/

#ifndef quantlib_pricers_jamshidian_swaption_h
#define quantlib_pricers_jamshidian_swaption_h

#include <ql/Pricers/swaptionpricer.hpp>
#include <ql/ShortRateModels/onefactormodel.hpp>

namespace QuantLib {

    namespace Pricers {

        //! Jamshidian swaption pricer
        class JamshidianSwaption : public 
            PricingEngines::GenericModelEngine<
                    ShortRateModels::OneFactorAffineModel,
                    Instruments::Swaption::arguments,
                    Instruments::Swaption::results > {
          public:
            JamshidianSwaption(
                const Handle<ShortRateModels::OneFactorAffineModel>& modl)
            : PricingEngines::GenericModelEngine<
                    ShortRateModels::OneFactorAffineModel,
                    Instruments::Swaption::arguments,
                    Instruments::Swaption::results >(modl) {} 
            void calculate() const;
          private:
            class rStarFinder;
            friend class rStarFinder;
        };

    }

}


#endif
