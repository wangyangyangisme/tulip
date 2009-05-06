#ifndef CURVES_H
#define CURVES_H
#ifndef DOXYGEN_NOTFOR_DEVEL
#include <tulip/Coord.h>
#include <tulip/Color.h>
#include "tulip/GlTools.h"
#include <vector>




namespace tlp {
  template<typename T, unsigned int N>
    class Matrix;
  void curveVisibility(const Coord &startPoint,const std::vector<Coord> &bends, const Coord &endPoint,
		       const Size &size, bool &polygon, bool &line, const Matrix<float,4> &projectionMatrix, const Matrix<float,4> &modelviewMatrix, const tlp::Vector<int, 4>&viewportArray);
  //====================================================================
  //return vertices, update startN and endN to prevent bad edge drawing
  std::vector<Coord> computeCleanVertices(const std::vector<Coord> &bends,
					  const Coord &startPoint, const Coord &endPoint,
					  Coord &startN, Coord &endN);
  void polyLine(const std::vector<Coord> &,/* polyline vertices */
		const Color &,             /* start color */
		const Color &);            /* end color */
  void polyLine(const std::vector<Coord> &, /* polyline vertices */
		const std::vector<Color> &);/* colors at polyline verts */
  void polyQuad(const std::vector<Coord> &, /* polyline vertces */
		const Color &,            /* start color */
		const Color &,            /* end color */
		const float,              /* start size */
		const float,              /* end size */
		const Coord &,            /* normal to the begin of the curve */
		const Coord &,            /* normal to the end curve */
		const std::string &textureName="");			/* textureName */
  void polyQuad(const std::vector<Coord> &, /* polyline vertces */
		const std::vector<Color> &, /* colors at polyline verts */
		const std::vector<float> &, /* size at polyline verts */
		const Coord &,            /* nomal to the begin of the curve */
		const Coord &,            /* nomal to the end curve */
		const std::string &textureName="");			/* textureName */
  void polyCylinder(const std::vector<Coord> &,    /* polyline vertces */
		    const std::vector<Color> &,    /* colors at polyline verts */
		    const std::vector<float> &,    /* size at polyline verts */
		    const Coord &,            /* nomal to the begin of the curve */
		    const Coord &);           /* nomal to the end curve */
  void polyCylinder(const std::vector<Coord> &,    /* polyline vertces */
		    const Color &,            /* start color */
		    const Color &,            /* end color */
		    const float,              /* start size */
		    const float,              /* end size */
		    const Coord &,            /* nomal to the begin of the curve */
		    const Coord &);           /* nomal to the end curve */
  //====================================================================
  void bezierCylinder(const std::vector<Coord> &,  /* polyline vertces */
		      const Color &,          /* start color */
		      const Color &,          /* end color */
		      const float,            /* start size */
		      const float,            /* end size */
		      const Coord &,          /* nomal to the begin of the curve */
		      const Coord &);         /* nomal to the end curve */
  void bezierQuad(const std::vector<Coord> &,  /* polyline vertces */
		  const Color &,          /* start color */
		  const Color &,          /* end color */
		  const float,            /* start size */
		  const float,            /* end size */
		  const Coord &,          /* nomal to the begin of the curve */
		  const Coord &);         /* nomal to the end curve */
  void bezierLine(const std::vector<Coord> &,  /* polyline vertces */
		  const Color &,          /* start color */
		  const Color &);          /* end color */
  //====================================================================
  void splineCylinder(const std::vector<Coord> &,  /* polyline vertces */
		      const Color &,          /* start color */
		      const Color &,          /* end color */
		      const float,            /* start size */
		      const float,            /* end size */
		      const Coord &,          /* nomal to the begin of the curve */
		      const Coord &);         /* nomal to the end curve */
  void splineQuad(const std::vector<Coord> &,  /* polyline vertces */
		  const Color &,          /* start color */
		  const Color &,          /* end color */
		  const float,            /* start size */
		  const float,            /* end size */
		  const Coord &,          /* nomal to the begin of the curve */
		  const Coord &);         /* nomal to the end curve */
  void splineLine(const std::vector<Coord> &,  /* polyline vertces */
		  const Color &,          /* start color */
		  const Color &);          /* end color */
  //====================================================================
  std::vector<Color> getColors(const std::vector<Coord> &line, const Color &c1, const Color &c2);
  std::vector<float> getSizes(const std::vector<Coord> &line, float s1, float s2);
  GLfloat* buildCurvePoints (const std::vector<Coord> &vertices,
      const std::vector<float> &sizes,
      const Coord &startN,
      const Coord &endN,
      unsigned int &resultSize,
      std::vector<unsigned int> *dec=NULL);
}
#endif //DOXYGEN_NOTFOR_DEVEL
#endif
