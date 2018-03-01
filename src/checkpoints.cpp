// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of // TODO: needs to adjusted for checkpoint checks, also see main.cpp
        (         0, uint256("0x4c9888c510519751ad41f4cebbe7d5e46c0423886ea3b44801fdc95e84176faa"))
        (     34336, uint256("0xfc6a3ee59b9f2429114178ff7a4792a7af102688156d26a3edbb90c243850dcd"))
        (     50000, uint256("0x5fa3d8bb008a55a1b6e301b435be3a68985083435748b913ef8572bf1282303c"))
        (     70000, uint256("0x7ee7864ffec5a23f526e01a1388a6e988d2773365522e04dd51d3c71c19b459f"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
// JC : no checkpoints for pigeoin
//        if (fTestNet) return true; // Testnet has no checkpoints
//        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
//        if (i == mapCheckpoints.end()) return true;
//        return hash == i->second;
	return true; 
    }

    int GetTotalBlocksEstimate()
    {
// JC : nocheckpoints for pigeoin
//        if (fTestNet) return 0;
//        return mapCheckpoints.rbegin()->first;
	return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
	if (true) return NULL; // JC : no checkpoints for pigeoin
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
